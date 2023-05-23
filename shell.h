#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdio.h>
int parseArguments(char *line, char **args);
void executeCommand(char *command);
void exitShell();
void printEnvironment();
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void handleExitCommand(char *command);
void handleSetenvCommand(char *command);
void handleUnsetenvCommand(char *command);
#endif 
