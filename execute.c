#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_PATH 1024
#include "shell.h"
void executeCommand(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        char *args[MAX_ARGS];
        int i = 0;

        args[i++] = strtok(command, " ");
        while (i < MAX_ARGS - 1) {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL)
                break;
            i++;
        }
        args[i] = NULL;

        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        wait(NULL);
    }
}
void exitShell() {
    printf("Exiting the shell...\n");
    exit(0);
}
