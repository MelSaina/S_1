#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_PATH 1024
#include "shell.h"
int main() {
    char *command;
    char *line = NULL;
    size_t size = 0;
    ssize_t lineSize;
    while (1) {
        printf("#cisfun$ ");

        lineSize = my_getline(&line, &size, stdin);

        if (lineSize == -1) {
            break;
        }

        command = strtok(line, "\n");

        if (strcmp(command, "cd") == 0) {
            char *arg = strtok(NULL, "\n");

            if (arg == NULL || arg[0] == '\0') {
                chdir("/");
            } else {
                chdir(arg);
            }
            continue;
        } else if (strcmp(command, "exit") == 0) {
            exitShell();
	}else if (strcmp(command, "env") == 0) {
            printEnvironment();
            continue;
        }
	 executeCommand(command);
        }
 
    free(line);
    return 0;
}
