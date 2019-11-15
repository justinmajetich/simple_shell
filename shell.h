#ifndef SHELL_H
#define SHELL_H

/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* HELPER FUNCTIONS */
int _strlen(char *s);
char *_strncpy(char *dest, const char *src, int n);

#endif
