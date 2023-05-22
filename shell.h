#include <stddef.h>
#include <stdio.h>
int parseArguments(char *line, char **args);
void executeCommand(char *command);
void exitShell();
void printEnvironment();
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
