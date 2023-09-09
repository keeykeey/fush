#ifndef FUSH_STRING
#define FUSH_STRING

// MACRO
#include "./fush_core.h"
#include "./fush_config.h"

// TYPE
typedef struct fush_str_s fush_str_t;
struct fush_str_s {
    fush_uint len;
    fush_uchar *data;
};

// PROTOTYPE
fush_str_t *init_fush_str(fush_uchar *data);
fush_uint fush_strcmp(const fush_str_t *src, fush_str_t *dst);

#endif