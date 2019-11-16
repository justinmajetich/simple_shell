#ifndef SHELL_H
#define SHELL_H

fhjaksfsl/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


/* MAIN FUNCTIONS */
char **_strtok(char *line);

/* STRING HELPER FUNCTIONS */
size_t _strlen(char *s);
char *_strncpy(char *dest, const char *src, size_t n);

#endif
