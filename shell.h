#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct string_list - Singly linked list
 * @string: A string
 * @next: A pointer to the next node
 */
typedef struct string_list
{
	char *string;
	struct string_list *next;
} s_list;

#endif
