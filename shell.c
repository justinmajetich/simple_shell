#include "shell.h"

/**
 * _getline - retrieve command line
 * @line: buffer to store command line
 * @size: length of command line
 *
 */
ssize_t _getline(char **line, size_t *line_size, FILE *stream)
{
	ssize_t read_cnt, read_total = 0;
	size_t offset; /* line offset for each iteration */
	char *buffer = alloc_mngr(buffer, (sizeof(char) * 1024));

	if (!buffer) /* error if malloc fail */
	{
		perror("Allocation failed");
		return (-1);
	}

	/* read stdin to dynamic buffer */
	while ((read_cnt = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
	{
		if (read_cnt == -1) /* check for read failure */
			return (-1);
		
		if (read_cnt) /* if new text read */
		{
			read_total += read_cnt; /* add num of bytes last read to total */

			/* reallocate line to receive new text */
			*line = alloc_mngr(&(*line), (sizeof(char) * read_total));
			if (!(*line)) /* check for reallocation fail */
			{
				perror("Reallocation failed");
				return (-1);
			}

			/* copy buffer to line from current offset */
			_strncpy(((*line) + offset), buffer, read_cnt);

			offset = read_total; /* advance line offset */
		}
		if ((*line)[offset - 1] == '\n') /* if line is \n terminated */
			break; /* break read loop */
	}
	(*line)[offset] = '\0'; /* null-terminate line */

	/* return total number of bytes read */
	return (*line_size = offset);
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
	char *line;
	size_t line_size = 0;

	/* print command prompt */
	write(1, "$ ", 2);

	/* read command line */
	_getline(&line, &line_size, STDIN_FILENO);

	/* parse command line */
	_strtok();

	/* execute command line */
	_execute();
}
