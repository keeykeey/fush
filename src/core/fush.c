#include "fush.h"
#include <stdio.h>
#include <string.h>

void catch_command_input(char command[INPUT_MAX_LEN])
{
    fputc('>', stdout);
    scanf("%[^\n]%*c", command);
}

command_t parse_command(char command[INPUT_MAX_LEN])
{
    command_t cmdt;
    int cc = 0;
    int cl = 0;
    for (int i = 0; i < COMMAND_LINE_MAX_LEN; i++ ) {
        if (command[i] < 'a' || command[i] > 'z') {
            while (command[i] < 'a' || command[i] > 'z') {
                i++;
            }
            cmdt.cline[cc][cl] = '\0';
            i -= 1;
            cl = 0;
            cc++;
        } else {
          cmdt.cline[cc][cl] = command[i];
          cl++;
        }
    }

    return cmdt;
}

int exec_command(command_t command)
{
    if (strcmp(command.cline[0], FUSH_STOP_COMMAND) == 0) {
        return FUSH_STOP_RUNNING;
    } else if(strcmp(command.cline[0], FUSH_TOUCH_COMMAND) == 0) {
        fush_touch(command);
        return FUSH_CONTINUE_RUNNING;
    } else {
        fush_echo(command);
        return FUSH_CONTINUE_RUNNING;
    }
}

int main(void) {
    int wait = FUSH_CONTINUE_RUNNING;
    while (wait) {
        char input[INPUT_MAX_LEN] = {'\0'};
        catch_command_input(input);

        command_t cmdt = parse_command(input);

        wait = exec_command(cmdt);
    }
    return 0;
}