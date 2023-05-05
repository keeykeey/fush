#ifndef FLUSH_H
#define FLUSH_H

// MACRO
#define COMMAND_LINE_MAX_LEN 30

// TYPE

typedef struct command_s command_t;
struct command_s {
    char      cline[COMMAND_LINE_MAX_LEN];
};

// PROTOTYPE
void catchCommandInput(char command[COMMAND_LINE_MAX_LEN]);
command_t parse_command(char command[COMMAND_LINE_MAX_LEN]);
int exec_command(command_t command);

#endif