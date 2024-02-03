#ifndef FUSH_H
#define FUSH_H

// MACRO
#define FUSH_STOP_RUNNING 0
#define FUSH_CONTINUE_RUNNING 1
#define INPUT_MAX_LEN 30
#define COMMAND_LINE_MAX_LEN 15
#define COMMAND_COUNT 2
#define FUSH_STOP_COMMAND "stop"

#include "fush_echo.h"
#include "fush_touch.h"

// TYPE
typedef struct command_s command_t;
struct command_s {
    char      cline[COMMAND_COUNT][COMMAND_LINE_MAX_LEN];
};

// PROTOTYPE
void catch_command_input(char input[INPUT_MAX_LEN]);
command_t parse_command(char input[INPUT_MAX_LEN]);
int exec_command(command_t command);

#endif