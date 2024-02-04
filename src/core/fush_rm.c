#include "./fush_rm.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

void fush_rm(command_t cmd)
{

    int isOption = fush_rm_has_option(cmd);

    if (isOption == FUSH_RM_WITHOUT_OPTION) {
        DIR *dir;
        if ((dir = opendir(cmd.cline[1])) != NULL) {
            fprintf(stderr, "failed to execute command\n");
            fprintf(stderr, "%s was directory not file use -r to remove directory\n", cmd.cline[1]);
            closedir(dir);
            return;
        }
        closedir(dir);

        remove(cmd.cline[1]);
        return;
    };

    if (cmd.cline[1][1] == 'r') {
        // TODO: it does not work for windows
        rmdir(cmd.cline[2]);
        return;
    };

    fprintf(stderr, "failed to execute command\n");

};

static int fush_rm_has_option(command_t cmd) {
    if (cmd.cline[1][0] == '-') {
        return FUSH_RM_WITH_OPTION;
    }

    return FUSH_RM_WITHOUT_OPTION;

};
