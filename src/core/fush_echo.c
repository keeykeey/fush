#include <stdio.h>
#include "./fush_core.h"
#include "./fush_config.h"

void fush_echo(command_t *cmd)
{
    if (cmd->cline->len < 1) return;
    for (fush_uint i=0; i < cmd->cline->len; i++) {
        putchar(*(cmd->cline->data));
        (cmd->cline->data)++;
    }
    putchar('\n');
}
