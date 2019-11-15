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

/**
 * struct string_list - Singly linked list
 * @token: A string
 * @next: A pointer to the next node
 */
typedef struct string_list
{
	char *token;
	s_list *next;
} s_list;

s_list *add_node_end(s_list **head, const char *tok);

void free_list(s_list *head);

#endif
