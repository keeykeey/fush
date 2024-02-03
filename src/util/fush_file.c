#include <stdio.h>

void fush_fcopy(FILE *src, FILE *dst) {
    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }
}