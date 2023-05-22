#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_PATH 1024
#include "shell.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
    static char buffer[BUFFER_SIZE];
    static size_t buffer_index = 0;
    static ssize_t bytes_read = 0;

    if (*n == 0 || *lineptr == NULL) {
        *n = BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
    }

    ssize_t chars_read = 0;
    int newline_found = 0;

    while (1) {
        if (buffer_index >= bytes_read) {
            bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
            buffer_index = 0;
            if (bytes_read == 0) {
                break;
            } else if (bytes_read == -1) {
                return -1;
            }
        }

        (*lineptr)[chars_read] = buffer[buffer_index];
        chars_read++;
        buffer_index++;

        if (buffer[buffer_index - 1] == '\n') {
            newline_found = 1;
            break;
        }

        if (chars_read >= *n) {
            *n += BUFFER_SIZE;
            char *new_lineptr = (char *)realloc(*lineptr, *n);
            if (new_lineptr == NULL) {
                return -1;
            }
            *lineptr = new_lineptr;
        }
    }

    (*lineptr)[chars_read] = '\0';

    if (newline_found) {
        return chars_read;
    } else {
        return -1;
    }
}
