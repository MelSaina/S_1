#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
void handleSetenvCommand(char *command) {
    char *space = strchr(command, ' ');
    char *space2 = strchr(space, ' ');

    if (space == NULL) {
        write(STDERR_FILENO, "Error: Invalid setenv command\n", strlen("Error: Invalid setenv command\n"));
        return;
    }
    space++;
   

    if (space2 == NULL) {
        write(STDERR_FILENO, "Error: Invalid setenv command\n", strlen("Error: Invalid setenv command\n"));
        return;
    }
    *space2 = '\0';
    space2++;
    if (*space == '\0' || *space2 == '\0') {
        write(STDERR_FILENO, "Error: Invalid setenv command\n", strlen("Error: Invalid setenv command\n"));
        return;
    }
    if (setenv(space, space2, 1) == -1) {
        write(STDERR_FILENO, "Error: Failed to set environment variable\n", strlen("Error: Failed to set environment variable\n"));
        return;
    }
}

void handleUnsetenvCommand(char *command) {
  
  char *space = strchr(command, ' ');

    if (space == NULL) {
        write(STDERR_FILENO, "Error: Invalid unsetenv command\n", strlen("Error: Invalid unsetenv command\n"));
        return;
    }

   
    space++;

   
    if (unsetenv(space) == -1) {
        write(STDERR_FILENO, "Error: Failed to unset environment variable\n", strlen("Error: Failed to unset environment variable\n"));
        return;
    }
}

