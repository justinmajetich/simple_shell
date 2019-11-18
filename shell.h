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

/**
 * struct built_ins - catalogue built-in functions
 * @cmd: command name
 * @fp: pointer to named function
 */
typedef struct built_in_fp
{
	char *cmd;
	int (*fp)(char * const*);
} built_in;

/* EXTERN VARIABLES */
mem_list *mem_head;

/* MAIN FUNCTIONS */
char **_strtok(char *line);

/* EXECUTION FUNCTIONS */
int exec_mngr(char *const *argv);
int exec_builtin(char *const *argv);
int exec_external(char *const *argv);

/* MEMORY FUNCTIONS */
char *alloc_mngr(char *ptr, size_t size);
mem_list *add_mem_node(mem_list **head, char *ptr);
void free_mem_list(mem_list **head);
char *_realloc(char *ptr, size_t new_size);

/* STRING HELPER FUNCTIONS */
size_t _strlen(char *s);
char *_strncpy(char *dest, const char *src, size_t n);

#endif
