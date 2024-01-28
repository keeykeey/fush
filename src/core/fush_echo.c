#include "./fush.h"
#include <stdio.h>

void fush_echo(command_t cmd)
{
    int i = 0;
    while(cmd.cline[i]) {
        fputc(cmd.cline[i++], stdout);
        if (i > COMMAND_LINE_MAX_LEN) {
        }
    }
    fputc('\n', stdout);
}
