#ifndef FUSH_RM
#define FUSH_RM

#include "./fush.h"

// MACRO
#define FUSH_RM_COMMAND "rm"
#define FUSH_RM_WITH_OPTION 1
#define FUSH_RM_WITHOUT_OPTION 0

// TYPE

// PROTOTYPE
void fush_rm(command_t cmd);
static int fush_rm_has_option(command_t cmd);

#endif