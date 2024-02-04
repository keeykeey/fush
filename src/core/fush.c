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
        if (!is_fush_command_c(command[i])) {
            while (!is_fush_command_c(command[i])) {
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

int is_fush_command_c(char c) {
    if (c >= 'a' && c <= 'z') {
        return VALID_COMMAND_CHAR;
    }
    if (c >= 'A' && c <= 'Z') {
        return VALID_COMMAND_CHAR;
    }
    if (c >= '0' && c <= '9') {
        return VALID_COMMAND_CHAR;
    }
    if (c == '.' || c == '-' || c == '_') {
        return VALID_COMMAND_CHAR;
    }

    return INVALID_COMMAND_CHAR;
}

int exec_command(command_t command)
{
    if (strcmp(command.cline[0], FUSH_STOP_COMMAND) == 0) {
        return FUSH_STOP_RUNNING;
    } else if(strcmp(command.cline[0], FUSH_TOUCH_COMMAND) == 0) {
        fush_touch(command);
    } else if(strcmp(command.cline[0], FUSH_CAT_COMMAND) == 0) {
        fush_cat(command);
    } else if(strcmp(command.cline[0], FUSH_RM_COMMAND) == 0) {
        fush_rm(command);
    } else {
        fush_echo(command);
    }
    return FUSH_CONTINUE_RUNNING;
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