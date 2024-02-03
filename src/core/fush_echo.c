#include "./fush.h"
#include <stdio.h>

void fush_echo(command_t cmd)
{
    for (int i = 0; i < COMMAND_COUNT; i++) {
        int j = 0;
        while (cmd.cline[i][j]) {
            fputc(cmd.cline[i][j++], stdout);
        }
        fputc(' ', stdout);
    }
    fputc('\n', stdout);
}
