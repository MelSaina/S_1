#include "shell.h"
#include <stdio.h>
void printEnvironment() {
    extern char **environ;
    char **env = environ;

    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}
