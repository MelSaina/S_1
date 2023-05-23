#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
void handleExitCommand(char *command) {
	int argStart = strlen("exit");
	int argEnd = strlen(command) - 1;
	char exitStatus[16];
	int status = atoi(exitStatus);
    while (command[argStart] == ' ') {
        argStart++;
    }
    if (command[argStart] == '\0') {
        exitShell(0);
    } else {
        while (argEnd > argStart && command[argEnd] == ' ') {
            argEnd--;
        }
	if (argEnd >= argStart) {
		strncpy(exitStatus, &command[argStart], argEnd - argStart + 1);
            exitStatus[argEnd - argStart + 1] = '\0';
	    exitShell(status);
        } else {
		write(STDERR_FILENO, "Error: Invalid argument 'exit'\n", 30);
        }
    }
}
