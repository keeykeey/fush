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

int exec_command(command_t command)
{
    if (strcmp(command.cline, "stop") == 0) {
        return 0;
    } else {
        int i = 0;
        while(command.cline[i]) {
            putchar(command.cline[i++]);
        }
        putchar('\n');
        return 1;
    }
}

int main(void) {
    int wait = 1;
    while (wait) {
        char c[30] = {};
        catchCommandInput(c);

        command_t cmdt = parse_command(c);

        wait = exec_command(cmdt);
    }
    return 0;
}