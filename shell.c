#include "shell.h"

void recieve_sig(int signal);

/**
 * main - loop through essential shell input and execution tasks
 *
 * Return: 0 or EXIT_SUCCESS on Sucess, EXIT_FAILURE on Failure
 */
int main(void)
{
	char *line = NULL;
	char **tok_array = NULL;
	size_t loop_cnt = 1; /* count iterations */

	do {
		line = NULL;
		tok_array = NULL;
		
		/* print command prompt */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		/* accounts for [CTRL + c] */
		signal(SIGINT, recieve_sig);

		/* read command line */
		if ((_getline(&line)) == 0)
		{
			free_mem_list(&mem_head);
			free_static_mem_list(&static_mem_head);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}

		/* set pointer array to parsed command line */
		if (line)
			tok_array = _strtok(line);
		
		if (tok_array) /* if token present */
			if ((exec_mngr(tok_array)) == -1) /* pass args to executor */
				print_err(loop_cnt);

		free_mem_list(&mem_head); /* free all allocated memory */

		loop_cnt++; /* increment loop count */

	} while (1);

	free_static_mem_list(&static_mem_head); /* free all persevering memory */
	return (0);
}

void recieve_sig(int signal __attribute__((unused)))
{
	/* prints the command line prompt */
	write(STDOUT_FILENO, "\n$ ", 3);
}
