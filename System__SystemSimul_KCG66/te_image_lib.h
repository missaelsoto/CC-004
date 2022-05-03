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

#ifndef _TE_IMAGE_LIB_H_
#define _TE_IMAGE_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

/* TeImage: TE image object */
typedef struct {
    unsigned char *buf; /* !! ==> RGBA <== !! buffer */
    unsigned int w;
    unsigned int h;
    unsigned char RGBAimage;
} TeImage;

/* Allocate a new TeImage variable, allocate image buffer, initialize attributes */
TeImage *te_new_image(unsigned w, unsigned h);

/* Allocate a new TeImage variable, does not allocate image buffer, initialize attributes */
TeImage *te_new_image_no_malloc(unsigned char *buf, unsigned w, unsigned h);

/* Free TeImage variable and associated buffer */
void te_free_image(TeImage *pImage);

/* Clear image pixels */
void te_clear_image(TeImage *pImage);

/* Flip image top <-> bottom */
void te_flipv_image(TeImage *pImage);

/* Compute mean absolute error (normalized) on actual image vs reference, considering filter (mask) */
int te_compute_mean_absolute_error(const TeImage *pActual, const TeImage *pReference, const TeImage *pFilter, double *pdMae, TeImage *pDiff, TeImage *pBinDiff);

/* Compute peak absolute error (normalized) on actual image vs reference, considering filter (mask) */
int te_compute_peak_absolute_error(const TeImage *pActual, const TeImage *pReference, const TeImage *pFilter, double *pdPae, TeImage *pDiff, TeImage *pBinDiff);

#ifdef __cplusplus
}
#endif

#endif /* _TE_IMAGE_LIB_H_ */