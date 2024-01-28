#include "fush.h"
#include <stdio.h>
#include <string.h>

void catch_command_input(char command[COMMAND_LINE_MAX_LEN])
{
    fputc('>', stdout);
    scanf("%[^\n]%*c", command);
}

command_t parse_command(char command[COMMAND_LINE_MAX_LEN])
{
    command_t cmdt;
    strcpy(cmdt.cline, command);

    return cmdt;
}

int exec_command(command_t command)
{
    if (strcmp(command.cline, FUSH_STOP_COMMAND) == 0) {
        return FUSH_STOP_RUNNING;
    } else {
        fush_echo(command);
        return FUSH_CONTINUE_RUNNING;
    }
}

int main(void) {
    int wait = FUSH_CONTINUE_RUNNING;
    while (wait) {
        char c[COMMAND_LINE_MAX_LEN] = {};
        catch_command_input(c);

        command_t cmdt = parse_command(c);

        wait = exec_command(cmdt);
    }
    return 0;
}