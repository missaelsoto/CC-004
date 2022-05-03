/*
 * Copyright(C) 2020 ANSYS, Inc. ALL RIGHTS RESERVED.
 * Copyright(C) 2017 ESTEREL TECHNOLOGIES SAS. ALL RIGHTS RESERVED.
 * This source file may be used and distributed without restriction provided
 * that this copyright statement is not removed from the file and that any
 * derivative work contains this copyright notice.
 *
 * Warranty
 * ANSYS, Inc  makes no warranty of any kind with regard to the
 * use of this Software, either expressed or implied, including, but not
 * limited to the fitness for a particular purpose.
 */


#include "SmuConfig.h"

/*****************************************************************************/

/* from/to string conversion*/

#define CHECK(c) if (!(c)) return 1
#define SKIP_WHITESPACE(str) while(*str == ' ' || *str == '\t') str++

int ssm_string_to_bool(const char *str, int *value, char **endptr) {
    char c;

    if (str == 0 || value == 0) {
        return 1;
    }

    *endptr = (char*)str;
    SKIP_WHITESPACE(str);
    c = *str++;
    /* tolower(str) matches "t" or "true" => 1 */
    /*                   or "f" or "false" => 0 */
    /* enptr set to the character after "t" or "f" or "true" or "false" */
    if (c == 't' || c == 'T') {
        *value = 1;
        *endptr = (char*)str;
        c = *str++;
        if (c == 'r' || c == 'R') {
            c = *str++;
            if (c == 'u' || c == 'U') {
                c = *str++;
                if (c == 'e' || c == 'E') {
                    *endptr = (char*)str;
                }
            }
        }
        return 0;
    }
    else if (c == 'f' || c == 'F') {
        *value = 0;
        *endptr = (char*)str;
        c = *str++;
        if (c == 'a' || c == 'A') {
            c = *str++;
            if (c == 'l' || c == 'L') {
                c = *str++;
                if (c == 's' || c == 'S') {
                    c = *str++;
                    if (c == 'e' || c == 'E') {
                        *endptr = (char*)str;
                    }
                }
            }
        }
        return 0;
    }

    return 1;
}

int ssm_char_to_string(char value, char *str) {
    switch (value) {
        case '\0': CHECK(ssm_sprintf(str, "'\\0'") >= 0); break;
        case '\t': CHECK(ssm_sprintf(str, "'\\t'") >= 0); break;
        case '\n': CHECK(ssm_sprintf(str, "'\\n'") >= 0); break;
        case '\r': CHECK(ssm_sprintf(str, "'\\r'") >= 0); break;
        default: {
            if (value < 32 || value > 126) {
                CHECK(ssm_sprintf(str, "'\\x%.2x'", (unsigned char)value) >= 0);
            }
            else {
                CHECK(ssm_sprintf(str, "'%c'", value) >= 0);
            }
        }
    }
    return 0;
}

int ssm_string_to_char_(const char *str, char *value, char **endptr) {
    char c = *(str++);
    /* detect some invalid or ill-formatted values */
    if (c == 0) return 1;
    /* detect and read classic value (non- backslash escape) */
    if (c != '\\') *value = c;
    /* detect backslash escape */
    else {
        c = *(str++);
        if (c == 0) return 1;
        /* detect and read ASCII hexadecimal code \xhh */
        if (c == 'x') {
            unsigned long u = 0;
            c = *(str++);
            if      (c >= '0' && c <= '9') u = (c - '0');
            else if (c >= 'a' && c <= 'f') u = (c - 'a' + 10);
            else if (c >= 'A' && c <= 'F') u = (c - 'A' + 10);
            else    return 1;
            c = *(str++);
            if      (c >= '0' && c <= '9') u = (u << 4) + (c - '0');
            else if (c >= 'a' && c <= 'f') u = (u << 4) + (c - 'a' + 10);
            else if (c >= 'A' && c <= 'F') u = (u << 4) + (c - 'A' + 10);
            else    return 1;
            *value = (char)u;
        }
        else {
            /* detect and read supported backslash escape */
            switch (c) {
                case '\'': *value = '\\'; str--; break;
                case '0': *value = '\0'; break;
                case 't': *value = '\t'; break;
                case 'n': *value = '\n'; break;
                case 'r': *value = '\r'; break;
                default: return 1;
            }
        }
    }
    *endptr = (char*)str;
    return 0;
}

int ssm_string_to_char(const char *str, char *value, char **endptr) {
    if (str == 0 || value == 0) {
        return 1;
    }
    *endptr = (char*)str;
    SKIP_WHITESPACE(str);
    if (*str != '\'')
        return 1;
    str++;
    
    if (ssm_string_to_char_(str, value, endptr) != 0) {
        return 1;
    }
    str = *endptr;
    if (*str != '\'')
        return 1;
    str++;
    *endptr = (char*)str;
    return 0;
}

#define ssm_int_to_string_(value, type, format) CHECK(ssm_sprintf(str, format, *(type*)value) >= 0)

int ssm_int_to_string(void *value, int size, int sign, char *str) {
    if (sign) {
        switch (size) {
            case 1: ssm_int_to_string_(value, char, "%d"); break;
            case 2: ssm_int_to_string_(value, short, "%d"); break;
            case 4: ssm_int_to_string_(value, long, "%ld"); break;
#           ifdef SSM_INT64
                case 8: {
                    ssm_int_to_string_(value, long long, "%" SSM_PRId64); break;
                }
#           endif
            default: return 1;
        }
    }
    else {
        switch (size) {
            case 1: ssm_int_to_string_(value, unsigned char, "%u"); break;
            case 2: ssm_int_to_string_(value, unsigned short, "%u"); break;
            case 4: ssm_int_to_string_(value, unsigned long, "%lu"); break;
#           ifdef SSM_INT64
                case 8: {
                    ssm_int_to_string_(value, unsigned long long, "%" SSM_PRIu64); break;
                }
#           endif
            default: return 1;
        }
    }
    return 0;
}

#define BYTETOBINARY(byte)  \
  ((byte) & 0x80 ? 1 : 0), \
  ((byte) & 0x40 ? 1 : 0), \
  ((byte) & 0x20 ? 1 : 0), \
  ((byte) & 0x10 ? 1 : 0), \
  ((byte) & 0x08 ? 1 : 0), \
  ((byte) & 0x04 ? 1 : 0), \
  ((byte) & 0x02 ? 1 : 0), \
  ((byte) & 0x01 ? 1 : 0) 

int ssm_int_to_base_string(void *value, int size, int sign, int base, char *str) {
    int i;
    switch (base) {
        case 2:
            *str++ = '0';
            *str++ = 'b';
            for (i = size - 1; i >= 0; --i) 
                str += ssm_sprintf(str, "%d%d%d%d%d%d%d%d", BYTETOBINARY(((unsigned char*)value)[i]));
            return 0;
        case 8:
            *str++ = '0';
            for (i = size - 1; i >= 0; --i) 
                str += ssm_sprintf(str, "%03o", ((unsigned char*)value)[i]);
            return 0;
        case 16:
            *str++ = '0';
            *str++ = 'x';
            for (i = size - 1; i >= 0; --i) 
                str += ssm_sprintf(str, "%02X", ((unsigned char*)value)[i]);
            return 0;
    }
    return ssm_int_to_string(value, size, sign, str);
}

#ifdef SSM_INT64
#   if _MSC_VER > 1200
#       define ssm_i64 __int64
#       define ssm_u64 unsigned __int64
#       define ssm_strtoi64 _strtoi64
#       define ssm_strtou64 _strtoui64
#   else
#       define ssm_i64 long long int
#       define ssm_u64 unsigned long long int
#       define ssm_strtoi64 strtoll
#       define ssm_strtou64 strtoull
#   endif
#endif

int ssm_string_to_int_(const char *str, void *value, unsigned size, unsigned sign, char **endptr) {
    char* str_end = (char*)str;
    int base = 0;
    int oor = 0;
    union {
        long i32;
        unsigned long u32;
#       ifdef SSM_INT64
            ssm_i64 i64;
            ssm_u64 u64;
#       endif
    } val;
    if (!str || !value) {
        return 1;
    }
    SKIP_WHITESPACE(str);
    if (!sign && str[0] == '-') { /* as standard is to overflow unsigned */
        return 1;
    }
    if (str[0] == '0') { 
        if (str[1] == 'b' || str[1] == 'B') {
            /* binary literals (+/- prefix not supported) */
            str += 2;
            base = 2;
        }
        else if (str[1] == 'x' || str[1] == 'X') {
            /* hexadecimal literals (+/- prefix not supported) */
            base = 16;
        }
        else {
            /* octal literals (+/- prefix not supported) */
            base = 8;
        }
    }
    ssm_errno = 0;
    switch (sign) {
        default:
            switch (size) {
                case 1: val.i32 = ssm_strtol(str, &str_end, base); break;
                case 2: val.i32 = ssm_strtol(str, &str_end, base); break;
                case 4: val.i32 = (base == 0) ? ssm_strtol(str, &str_end, base)
                                              : (long)ssm_strtoul(str, &str_end, base); 
                    break;
#           ifdef SSM_INT64
                case 8: val.i64 = (base == 0) ? ssm_strtoi64(str, &str_end, base)
                                               : (ssm_i64)ssm_strtou64(str, &str_end, base);
                    break;
#           endif
                default: return 1;
            }
            break;
        case 0:
            switch (size) {
                case 1: val.u32 = ssm_strtoul(str, &str_end, base); break;
                case 2: val.u32 = ssm_strtoul(str, &str_end, base); break;
                case 4: val.u32 = ssm_strtoul(str, &str_end, base); break;
#           ifdef SSM_INT64
                case 8: val.u64 = ssm_strtou64(str, &str_end, base); break;
#           endif
                default: return 1;
            }
    }
    switch (sign) {
        default:
            switch (size) {
                case 1: oor = (base == 0) ? (val.i32 < SSM_SCHAR_MIN || val.i32 > SSM_SCHAR_MAX)/* decimal */
                                          : (val.i32 > SSM_UCHAR_MAX);                          /* hexa, octal or binary */
                        break;
                case 2: oor = (base == 0) ? (val.i32 < SSM_SHRT_MIN || val.i32 > SSM_SHRT_MAX)  /* decimal */
                                          : (val.i32 > SSM_USHRT_MAX);                          /* hexa, octal or binary */
                    break;
                case 4: /* ERANGE */
                case 8: oor = 0; break;
            }
        break;
        case 0:
            switch (size) {
                case 1: oor = val.u32 > SSM_UCHAR_MAX; break;
                case 2: oor = val.u32 > SSM_USHRT_MAX; break;
                case 4: /* ERANGE */
                case 8: oor = 0; break;
            }
    }
    if (ssm_errno == SSM_ERANGE || str_end == str || oor) {
        return 1;
    }
    if (endptr) *endptr = str_end;
    switch (sign) {
        default:
            switch (size) {
                case 1: *(char*)value = (char)val.i32; break;
                case 2: *(short*)value = (short)val.i32; break;
                case 4: *(long*)value = val.i32; break;
#               ifdef SSM_INT64
                    case 8: *(ssm_i64*)value = val.i64; break;
#               endif
            }
            break;
        case 0:
            switch (size) {
                case 1: *(unsigned char*)value = (unsigned char)val.u32; break;
                case 2: *(unsigned short*)value = (unsigned short)val.u32; break;
                case 4: *(unsigned long*)value = val.u32; break;
#               ifdef SSM_INT64
                    case 8: *(ssm_u64*)value = val.u64; break;
#               endif
            }
    }
    return 0;
}

int ssm_string_to_int(const char *str, void *value, int size, int sign, char **endptr) {
    return ssm_string_to_int_(str, value, (unsigned)size, (unsigned)sign, endptr);
}

#define ssm_is_(f) ((size == sizeof(float) && f(*(float*)value)) || (size == sizeof(double) && f(*(double*)value)))

int ssm_real_to_string_(const void *value, unsigned size, const char *format, char *buffer, int advanced_te_check) {
    char *p;
    *buffer = '\0';
    if (advanced_te_check && ssm_is_(ssm_is_nan_xnan)) {
        CHECK(ssm_sprintf(buffer, "NaN") >= 0);
    }
    else if (advanced_te_check && ssm_is_(ssm_is_nan_pzero)) {
        CHECK(ssm_sprintf(buffer, "0.0") >= 0);
    }
    else if (ssm_is_(ssm_is_qnan)) {
        CHECK(ssm_sprintf(buffer, "qNaN") >= 0);
    }
    else if (ssm_is_(ssm_is_snan)) {
        CHECK(ssm_sprintf(buffer, "sNaN") >= 0);
    }
    else if (ssm_is_(ssm_is_nan)) {
        CHECK(ssm_sprintf(buffer, "NaN") >= 0);
    }
    else if (ssm_is_(ssm_is_inf)) {
        CHECK(ssm_sprintf(buffer, ssm_is_(ssm_sign_bit) ? "-Inf" : "+Inf") >= 0);
    }
    else {
        if (size == sizeof(float)) {
            if (!advanced_te_check && *(float*)value == 0.0f && ssm_sign_bit_flt(*(float*)value)) {
                CHECK(ssm_sprintf(buffer, format, -(*(float*)value)) >= 0);     /* to avoid -0.0 display */
            }
            else {
                CHECK(ssm_sprintf(buffer, format, *(float*)value) >= 0);
            }
        }
        else /*if (size == sizeof(double))*/ {
            if (!advanced_te_check && *(double*)value == 0.0 && ssm_sign_bit_dbl(*(double*)value)) {
                CHECK(ssm_sprintf(buffer, format, -(*(double*)value)) >= 0);    /* to avoid -0.0 display */
            }
            else {
                CHECK(ssm_sprintf(buffer, format, *(double*)value) >= 0);
            }
        }
        p = &buffer[0];
        while (*p && *p != '.' && *p != 'e' && *p != 'E') ++p;
        if (!*p) { /* .0 */
            p[0] = '.', p[1] = '0', p[2] = '\0';
        }
    }
    return 0;
}

int ssm_float_to_string(float value, const char *format, char *buffer, int advanced_te_check) {
    return ssm_real_to_string_(&value, sizeof(float), format, buffer, advanced_te_check);
}

int ssm_double_to_string(double value, const char *format, char *buffer, int advanced_te_check) {
    return ssm_real_to_string_(&value, sizeof(double), format, buffer, advanced_te_check);
}

#define IS_SUFFIX(c) ((c) != ' ' && (c) != '\t' && (c) != '\0')

int ssm_string_to_real_(const char *str, void *value, unsigned size, char **endptr, int advanced_te_check) {
    if (str == NULL || value == NULL) {
        return 1;
    }
    SKIP_WHITESPACE(str);
    ssm_errno = 0;
    if (ssm_strncmp(str, "qNaN", 4) == 0) {
        if (size == 4)  *(float*)value = (float)ssm_qnan_32;
        else            *(double*)value = ssm_qnan_64;
        *endptr = (char*)str + 4;
    }
    else if (ssm_strncmp(str, "sNaN", 4) == 0) {
        if (size == 4)  *(float*)value = (float)ssm_snan_32;
        else            *(double*)value = ssm_snan_64;
        *endptr = (char*)str + 4;
    }
    else if (ssm_strncmp(str, "NaN", 3) == 0) {
        if (advanced_te_check){
            if (size == 4)  *(float*)value = ssm_nan_xnan_32;
            else            *(double*)value = ssm_nan_xnan_64;
        }
        else {
            if (size == 4)  *(float*)value = (float)ssm_nan();
            else            *(double*)value = ssm_nan();
        }
        *endptr = (char*)str + 3;
    }
    else if (ssm_strncmp(str, "+Inf", 4) == 0) {
        if (size == 4)  *(float*)value = (float)ssm_inf();
        else            *(double*)value = ssm_inf();
        *endptr = (char*)str + 4;
    }
    else if (ssm_strncmp(str, "-Inf", 4) == 0) {
        if (size == 4)  *(float*)value = (float)(-1.0 * ssm_inf());
        else            *(double*)value = -1.0 * ssm_inf();
        *endptr = (char*)str + 4;
    }
    else {
        double const d = ssm_strtod(str, endptr);
        /* detect some invalid cases */
        int const oor = size == 4 ?
            (d > SSM_FLT_MAX || d < -SSM_FLT_MAX) :
            0 /* ERANGE */;
        int const denorm = (size == 4) ?
            (d > 0.0 && d < SSM_FLT_MIN) || (d < 0.0 && d > -SSM_FLT_MIN) :
            (d > 0.0 && d < SSM_DBL_MIN) || (d < 0.0 && d > -SSM_DBL_MIN);
        if ((ssm_errno == SSM_ERANGE && !denorm) || *endptr == str || oor) {
            return 1;
        }
        if (ssm_is_inf_dbl(d)) {
            return 1; /* strtod accepts case-insesitive INF or INFINITY with optional sign */
        }
        if (advanced_te_check && d == 0.0 && *str == '+') {
            if (size == 4)  *(float*)value = ssm_nan_pzero_32;
            else            *(double*)value = ssm_nan_pzero_64;
        }
        else {
            if (size == 4)  *(float*)value = (float)d;
            else            *(double*)value = d;
        }
    }
    return IS_SUFFIX(**endptr) ? 1 : 0; /* check for prefix, ex. nanxxx */
}

int ssm_string_to_float(const char *str, float *value, char **endptr, int advanced_te_check) {
    return ssm_string_to_real_(str, value, sizeof(float), endptr, advanced_te_check);
}

int ssm_string_to_double(const char *str, double *value, char **endptr, int advanced_te_check) {
    return ssm_string_to_real_(str, value, sizeof(double), endptr, advanced_te_check);
}
