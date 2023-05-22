#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int parseArguments(char *line, char **args) {
    int count = 0;
    char *token = strtok(line, " \t\n");

    while (token != NULL && count < MAX_ARGS - 1) {
        args[count] = token;
        count++;
        token = strtok(NULL, " \t\n");
    }

    args[count] = NULL;
    return count;
}
