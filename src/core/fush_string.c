#include <stdio.h>
#include <stdlib.h>
#include "./fush_string.h"
#include "./fush_core.h"

fush_str_t *init_fush_str(fush_uchar *data) {
    fush_uchar len = 0;
    fush_uchar *d = data;
    while (*d) {
        len++;
        d++;
    }

    // TODO: mallocで割り当てるサイズはlenでいいのか
    fush_str_t *s = (fush_str_t *)malloc(len);
    s->data = data;
    s->len = len;
    return s;
}

fush_uint fush_strcmp(const fush_str_t *src, fush_str_t *dst) {
    /*
     * 二つの文字を比較して、同じであれば0を返す。
     * 同じでなけば1を返す。
     */
    for (fush_uint i=0; i < src->len; i++) {
        if (*(src->data) != *(dst->data)) {
            return FUSH_NG;
        };
    }
    return FUSH_OK;
}
