#include "shell.h"

/**
 * _getline - retrieve command line
 * @line: buffer to store command line
 * @size: length of command line
 *
 */
ssize_t _getline(char **line)
{
	ssize_t read_cnt;

	/* read stdin to dynamic buffer */
	read_cnt = read(STDIN_FILENO, *line, ARG_MAX);
	if (read_cnt < 0) /* check for read failure */
		return (-1);

	(*line)[read_cnt] = '\0'; /* null-terminate */

	/* return total number of bytes read */
	return (read_cnt);
}

/**
 * _strtok -
 *
 *
 */
char *_strtok(char *line)
{
}

/**
 *
 *
 */
_execute(char *tok)
{
	execve();
}

/**
 *
 *
 *
 */
void main(void)
{
	char *line = malloc(sizeof(char) * ARG_MAX);

	/* check for allocation fail */
	if (!line)
		perror("Failed to allocate buffer");

	/* print command prompt */

	/* read command line */
	_getline(&line);

	/* parse command line */
	_strtok();

	/* execute command line */
	_execute();
}
