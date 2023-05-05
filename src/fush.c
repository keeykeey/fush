#include "fush.h"
#include <stdio.h>
#include <string.h>

void catchCommandInput(char command[COMMAND_LINE_MAX_LEN])
{
    putchar('>');
    scanf("%[^\n]%*c",command);
}

command_t parse_command(char command[COMMAND_LINE_MAX_LEN])
{
    command_t cmdt;
    strcpy(cmdt.cline, command);

    return cmdt;
}

void exec_command(command_t command)
{
    int i = 0;
    while(command.cline[i]) {
        putchar(command.cline[i++]);
    }
    putchar('\n');
}

int main(void) {
    char c[30] = {};
    catchCommandInput(c);

    command_t cmdt = parse_command(c);
    exec_command(cmdt);

    return 0;
}