#include "shell.h"
/**
 * main - loop through essential shell input and execution tasks
 */
int main(void)
{
	char *line = NULL;
	size_t line_size = 0;
	char **tok_array = NULL;
	int i = 0;

	/* print command prompt */
	write(1, "$ ", 2);

	/* read command line */
	_getline(&line, &line_size);

	/* set 2D array to parsed command line */
	tok_array = _strtok(line);

	for (i = 0; tok_array[i] != NULL; i++)
		printf("%s\n", tok_array[i]);

	/* INSERT EXECUTE FUNCTIONS */

	/* Free everything allocated */
	free_mem_list(&mem_head);

	return (0);
}
