#include "./fush.h"
#include "../util/fush_file.h"
#include <stdio.h>

void fush_cat(command_t cmd)
{
    FILE *fp;
    if ((fp = fopen(cmd.cline[1], "r")) == NULL) {
        fprintf(stderr, "failed to open the file\n");
    } else {
        fush_fcopy(fp, stdout);
        fputc('\n', stdout);
    }
    fclose(fp);
};
