#include <stdio.h>
#include "./fush.h"

void fush_touch(command_t cmd)
{
    if ( *cmd.cline[1] == '\0') return;

    FILE *fp;
    char *fname = cmd.cline[1];

    if ((fp = fopen(fname, "a")) == NULL) {
        fprintf(stderr, "failed to exec command\n");
    }
    fclose(fp);
}