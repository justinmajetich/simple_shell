#ifndef SHELL_H
#define SHELL_H

/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <limits.h>

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
typedef struct built_ins
{
	char *cmd;
	int (*fp)(char * const*);
} built_in;

/* EXTERN VARIABLES */
extern mem_list *mem_head;
mem_list *mem_head;
extern char **environ;

/* MAIN FUNCTIONS */
char **_strtok(char *line);
ssize_t _getline(char **line, size_t *line_size);
char **get_path(char * const *argv);

/* EXECUTION FUNCTIONS */
int exec_mngr(char *const *argv);
int exec_builtin(char *const *argv);
int exec_external(char *const *argv);

/* MEMORY FUNCTIONS */
char *alloc_mngr(char *ptr, size_t size);
mem_list *add_mem_node(mem_list **head, char *ptr);
void free_mem_list(mem_list **head);
char *_realloc(char *ptr, size_t new_size);
char *_memset(char *s, char b, unsigned int n);

/* STRING HELPER FUNCTIONS */
size_t _strlen(char *s);
char *_strncpy(char *dest, const char *src, size_t n);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

/* BUILT-IN FUNCTIONS */
int builtin_exit(char *const *argv);

#endif
