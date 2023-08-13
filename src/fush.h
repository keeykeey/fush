#ifndef FUSH_H
#define FUSH_H

// MACRO
#define FUSH_STOP_RUNNING 0
#define FUSH_CONTINUE_RUNNING 1
#define COMMAND_LINE_MAX_LEN 30

#include "fush_echo.h"

// TYPE

typedef struct command_s command_t;
struct command_s {
    char      cline[COMMAND_LINE_MAX_LEN];
};

// PROTOTYPE
void catch_command_input(char command[COMMAND_LINE_MAX_LEN]);
command_t parse_command(char command[COMMAND_LINE_MAX_LEN]);
int exec_command(command_t command);

#endif