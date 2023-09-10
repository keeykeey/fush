#ifndef FUSH_H
#define FUSH_H

// MACRO
#define FUSH_STOP_RUNNING 0
#define FUSH_CONTINUE_RUNNING 1

#include "./fush_core.h"
#include "./fush_config.h"

// TYPE
typedef struct command_s command_t;
struct command_s {
    fush_str_t      *cline;
};

// PROTOTYPE
void catch_command_input(fush_str_t *input_str);
command_t *parse_command(char *fush_str_t);

#endif