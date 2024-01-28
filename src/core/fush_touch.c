#include <stdio.h>
#include "./fush.h"

void fush_touch(command_t cmd)
{
    FILE *fp;
    if ((fp = fopen("touch_test.txt", "a")) == NULL) {
        fprintf(stderr, "failed to exec command\n");
    }
    fclose(fp);
}