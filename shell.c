#include "shell.h"
/**
 * main - loop through essential shell input and execution tasks
 *
 * Return: 0 or EXIT_SUCCESS on Sucess, EXIT_FAILURE on Failure
 */
int main(void)
{
	char *line = NULL;
	size_t line_size = 0;
	char **tok_array = NULL;
	int loop = 1; /* loop = temp loop driver */

	do {
		line = NULL;
		tok_array = NULL;

		/* print command prompt */
		write(1, "$ ", 2);

		/* read command line */
		_getline(&line, &line_size);

		/* set pointer array to parsed command line */
		tok_array = _strtok(line);
		
		if (tok_array) /* if token present */
			if ((exec_mngr(tok_array)) == -1) /* pass args to executor */
				perror("hsh"); /* print error on failure */

		free_mem_list(&mem_head); /* free all allocated memory */

	} while (loop);

	return (0);
}
