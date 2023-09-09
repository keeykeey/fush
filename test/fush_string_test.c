#include <stdio.h>
#include <stdlib.h>
#include "./test.h"
#include "../src/core/fush_string.h"
#include "../src/core/fush_core.h"

int test_init_fush_str(void)
{
    fush_uchar uc[10] = "hello cat";
    fush_str_t *s = init_fush_str(uc);
    int e = 9;
    int got = s->len;
    if (got != e) {
        printf(" test_init_fush_str failed: expect %d, got %d\n", e, got);
        return FUSH_TEST_NG;
    }

    for ( int i = 0; i < s->len; i++) {
        fush_uchar e = uc[i];
        fush_uchar got = *(s->data);
        if (*(s->data) != uc[i]) {
            printf(" test_init_fush_str failed: expect word %c, got %c\n", e, got);
            return FUSH_TEST_NG;
        }
        s->data++;
    }
    printf(" test_init_fush_str ok\n");
    free(s);
    return FUSH_TEST_OK;
}

int test_fush_strcmp(void)
{
    fush_str_t s1, s2;
    fush_uchar data1[3] = "ab";
    fush_uchar data2[3] = "ab";

    s1.len = 3;
    s1.data = data1;
    s2.len = 3;
    s2.data = data2;

    fush_uint d = fush_strcmp(&s1, &s2);
    fush_uint e = FUSH_OK;

    
    if (d != e) {
      printf(" test_fush_strcmp failed: expect %d, got %d\n", e, d);
      return FUSH_TEST_NG;
    }

    printf(" test_fush_strcmp ok\n");
    return FUSH_TEST_OK;
}

int main(void)
{
    // Init
    fush_uint count_test_run = 0, count_test_ng = 0;
    printf("\n--- TEST fush_string_test.c ---\n");

    // TEST: test_init_fush_str
    int ret = test_init_fush_str();
    count_test_run++;
    count_test_ng += ret;
    
    // TEST: test_fush_strcmp()
    ret = test_fush_strcmp();
    count_test_run++;
    count_test_ng += ret;

    printf("\n--- TEST RESULT ---\n total test run   : %d\n total test failed: %d\n", count_test_run, count_test_ng);
    
    return 0;
}