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

/* STRUCTS */
/**
 * struct allocation_history - tracks and stores allocations
 * @mem_ptr: pointer to allocated memory
 * @next: pointer to next node in list
 *
 * Description: stores a pointer to each allocation, allowing
 * greater organization and more efficient freeing
 */
typedef struct allocation_history
{
	char *mem_ptr;
	struct allocation_history *next;

} mem_list;

/* EXTERN VARIABLES */
extern mem_list *mem_head = NULL;

/* MAIN FUNCTIONS */
char **_strtok(char *line);

/* STRING HELPER FUNCTIONS */
size_t _strlen(char *s);
char *_strncpy(char *dest, const char *src, size_t n);

#endif
