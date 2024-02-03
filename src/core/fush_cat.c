#include "./fush.h"
#include <stdio.h>

static void copy(FILE *src, FILE *dst) {
    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }
}

void fush_cat(command_t cmd)
{
    FILE *fp;
    if ((fp = fopen(cmd.cline[1], "r")) == NULL) {
        fprintf(stderr, "failed to open the file\n");
    } else {
        int i = 0;
        char c[] = {};
        copy(fp, stdout);
        fputc('\n', stdout);
    }
    fclose(fp);
};
