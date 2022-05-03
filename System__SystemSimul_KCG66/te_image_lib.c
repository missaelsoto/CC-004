/*
 * Copyright(C) 2020 ANSYS, Inc. ALL RIGHTS RESERVED.
 * This source file may be used and distributed without restriction provided
 * that this copyright statement is not removed from the file and that any
 * derivative work contains this copyright notice.
 *
 * Warranty
 * ANSYS, Inc  makes no warranty of any kind with regard to the
 * use of this Software, either expressed or implied, including, but not
 * limited to the fitness for a particular purpose.
 */

#include "te_image_lib.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

TeImage *te_new_image(unsigned w, unsigned h)
{
    size_t lSize = 4 * w * h * sizeof(char);
    TeImage* pImage = (TeImage*)malloc(sizeof(TeImage));
    pImage->buf = malloc(lSize); 
    memset(pImage->buf, 0, lSize);
    pImage->w = w;
    pImage->h = h;
    pImage->RGBAimage = 1;
    return pImage;
}

TeImage *te_new_image_no_malloc(unsigned char *buf, unsigned w, unsigned h)
{
    size_t lSize = 4 * w * h * sizeof(char);
    TeImage* pImage = (TeImage*)malloc(sizeof(TeImage));
    pImage->buf = buf;
    pImage->w = w;
    pImage->h = h;
    pImage->RGBAimage = 1;
    return pImage;
}

void te_free_image(TeImage *pImage)
{
    if (pImage) {
        if (pImage->buf)
            free(pImage->buf);
        pImage->buf = 0;
        pImage->w = 0;
        pImage->h = 0;
        free(pImage);
    }
}

/* Clear image pixels */
void te_clear_image(TeImage *pImage)
{
    memset(pImage->buf, 0, (4 * pImage->w * pImage->h * sizeof(unsigned char))); 
}

/* Flip image top <-> bottom */
void te_flipv_image(TeImage *pImage)
{
    unsigned int line_size;
    unsigned char *tmp, *top, *bottom;
    line_size = pImage->w * 4;
    tmp = malloc(line_size);
    top = pImage->buf;
    bottom = pImage->buf + (pImage->h-1) * line_size;
    for ( ; top<bottom; top+= line_size, bottom -= line_size) {
        memcpy(tmp, top, line_size);
        memcpy(top, bottom, line_size);
        memcpy(bottom, tmp, line_size);
    }
    free(tmp);
}

/* helpers */
unsigned char* te_set_pixel(unsigned char *pPixel, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    *(pPixel + 0) = r;
    *(pPixel + 1) = g;
    *(pPixel + 2) = b;
    *(pPixel + 3) = a;
    return pPixel + 4;
}

unsigned char* te_get_pixel(unsigned char *pPixel, unsigned char *pR, unsigned char *pG, unsigned char *pB, unsigned char *pA)
{
    *pR = *(pPixel + 0);
    *pG = *(pPixel + 1);
    *pB = *(pPixel + 2);
    *pA = *(pPixel + 3);
    return pPixel + 4;
}

/* Compute mean absolute error (normalized) on actual image vs reference, considering filter (mask) */
int te_compute_mean_absolute_error(const TeImage *pActual, const TeImage *pReference, const TeImage *pFilter, double *pdMae, TeImage *pDiff, TeImage *pBinDiff)
{
    unsigned int i, w, h;
    double dMAE = 0.0;
    unsigned char *pPixelActual, *pPixelReference, *pPixelFilter, *pPixelDiff, *pPixelBinDiff;
    
    /* check mandatory input images */
    if (!pActual || !pReference)
        return 0;

    w = pActual->w;
    h = pActual->h;
    pPixelActual = pActual->buf;
    pPixelReference = pReference->buf;
    pPixelFilter = pFilter ? pFilter->buf : 0;
    pPixelDiff = pDiff ? pDiff->buf : 0;
    pPixelBinDiff = pBinDiff ? pBinDiff->buf : 0;

    /* check input & output images dimensions */
    if (w != pReference->w
        || (pFilter && w != pFilter->w)
        || (pDiff && w != pDiff->w)
        || (pBinDiff && w != pBinDiff->w)
        || h != pReference->h
        || (pFilter && h != pFilter->h)
        || (pDiff && h != pDiff->h)
        || (pBinDiff && h != pBinDiff->h))
        return 0;

    double nbPixels = 0.0;

    /* iterate on images pixels */
    for (i = 0; i < w*h * 4; i += 4) {
        /* consider pixel only if no filter or if filter pixel is not pure black */
        double rae=0.0, gae = 0.0, bae = 0.0, aae = 0.0, dae = 0.0;
        unsigned char bin_diff_color = 255;
        unsigned char rf = 255, gf = 255, bf = 255, af = 255;
        unsigned char r1 = 0, g1 = 0, b1 = 0, a1 = 0;
        unsigned char r2 = 0, g2 = 0, b2 = 0, a2 = 0;

        pPixelActual = te_get_pixel(pPixelActual, &r1, &g1, &b1, &a1);
        a1 = pReference->RGBAimage ? a1 : 255;
        pPixelReference = te_get_pixel(pPixelReference, &r2, &g2, &b2, &a2);

        if (pPixelFilter) {
            pPixelFilter = te_get_pixel(pPixelFilter, &rf, &gf, &bf, &af);
        }
        if (rf == 0 && gf == 0 && bf == 0) {
            bin_diff_color = 128;
        }
        else {
            rae = ((double)(r1*a1) - (double)(r2 * a2)) / 255.0;
            gae = ((double)(g1*a1) - (double)(g2 * a2)) / 255.0;
            bae = ((double)(b1*a1) - (double)(b2 * a2)) / 255.0;
            aae = (a1 - a2);

            dae = sqrt(rae*rae + gae*gae + bae*bae + aae*aae);
            nbPixels += 1.0;

            bin_diff_color = (dae != 0.0 ? 255 : 0);
        }
        if (pPixelDiff) {
            pPixelDiff = te_set_pixel(pPixelDiff, (unsigned char)abs(r1 - r2), (unsigned char)abs(g1 - g2), (unsigned char)abs(b1 - b2),
                (pActual->RGBAimage) ? (unsigned char)abs(a1 - a2) : 255);
        }
        if (pPixelBinDiff) {
            pPixelBinDiff = te_set_pixel(pPixelBinDiff, bin_diff_color, bin_diff_color, bin_diff_color, 255);
        }
        dMAE += dae;
    }
    if (nbPixels > 0.0) {
        *pdMae = (dMAE / (nbPixels * 510.0)); /* % */
    }
    else {
        *pdMae = 0.0;
    }

    return 1;
}

/* Compute peak absolute error (normalized) on actual image vs reference, considering filter (mask) */
int te_compute_peak_absolute_error(const TeImage *pActual, const TeImage *pReference, const TeImage *pFilter, double *pdPae, TeImage *pDiff, TeImage *pBinDiff)
{
    unsigned int i, w, h;
    unsigned char *pPixelActual, *pPixelReference, *pPixelFilter, *pPixelDiff, *pPixelBinDiff;

    *pdPae = 0.0;

    /* check mandatory input images */
    if (!pActual || !pReference)
        return 0;

    w = pActual->w;
    h = pActual->h;
    pPixelActual = pActual->buf;
    pPixelReference = pReference->buf;
    pPixelFilter = pFilter ? pFilter->buf : 0;
    pPixelDiff = pDiff ? pDiff->buf : 0;
    pPixelBinDiff = pBinDiff ? pBinDiff->buf : 0;

    /* check input & output images dimensions */
    if (w != pReference->w
        || (pFilter && w != pFilter->w)
        || (pDiff && w != pDiff->w)
        || (pBinDiff && w != pBinDiff->w)
        || h != pReference->h
        || (pFilter && h != pFilter->h)
        || (pDiff && h != pDiff->h)
        || (pBinDiff && h != pBinDiff->h))
        return 0;

    /* iterate on images pixels */
    for (i = 0; i < w*h * 4; i += 4) {
        /* consider pixel only if no filter or if filter pixel is not pure black */
        double rae = 0.0, gae = 0.0, bae = 0.0, aae = 0.0, dae = 0.0;
        unsigned char bin_diff_color = 255;
        unsigned char rf = 255, gf = 255, bf = 255, af = 255;
        unsigned char r1 = 0, g1 = 0, b1 = 0, a1 = 0;
        unsigned char r2 = 0, g2 = 0, b2 = 0, a2 = 0;

        pPixelActual = te_get_pixel(pPixelActual, &r1, &g1, &b1, &a1);
        a1 = pReference->RGBAimage ? a1 : 255;
        pPixelReference = te_get_pixel(pPixelReference, &r2, &g2, &b2, &a2);

        if (pPixelFilter) {
            pPixelFilter = te_get_pixel(pPixelFilter, &rf, &gf, &bf, &af);
        }
        if (rf == 0 && gf == 0 && bf == 0) {
            bin_diff_color = 128;
        }
        else {
            rae = ((double)(r1*a1) - (double)(r2 * a2)) / 255.0;
            gae = ((double)(g1*a1) - (double)(g2 * a2)) / 255.0;
            bae = ((double)(b1*a1) - (double)(b2 * a2)) / 255.0;
            aae = (a1 - a2);

            dae = sqrt(rae*rae + gae * gae + bae * bae + aae * aae) / 510.0;

            if (dae > *pdPae)
                *pdPae = dae;
            bin_diff_color = (dae != 0.0 ? 255 : 0);
        }
        if (pPixelDiff) {
            pPixelDiff = te_set_pixel(pPixelDiff, (unsigned char)abs(r1 - r2), (unsigned char)abs(g1 - g2), (unsigned char)abs(b1 - b2),
                (pActual->RGBAimage) ? (unsigned char)abs(a1 - a2) : 255);
        }
        if (pPixelBinDiff) {
            pPixelBinDiff = te_set_pixel(pPixelBinDiff, bin_diff_color, bin_diff_color, bin_diff_color, 255);
        }
    }

    return 1;
}
