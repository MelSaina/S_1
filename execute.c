#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_PATH 1024
#include "shell.h"

void executeCommand(char *command) {
    pid_t pid;
    pid = fork();

    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        char *args[MAX_ARGS];
        int numArgs = parseArguments(command, args);

        if (numArgs > 0) {
            execvp(args[0], args);
            perror(args[0]);
        }

        exit(0);
    } else {
        wait(NULL);
    }
}
void exitShell() {
    printf("Exiting the shell...\n");
    exit(0);
}
