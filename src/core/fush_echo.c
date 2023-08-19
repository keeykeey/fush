#include "./fush.h"
#include <stdio.h>

void fush_echo(command_t cmd)
{
    int i = 0;
    while(cmd.cline[i]) {
        putchar(cmd.cline[i++]);
        if (i > COMMAND_LINE_MAX_LEN) {
        }
    }
    putchar('\n');
}
