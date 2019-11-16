#include "shell.h"
nfjasdk
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
	char *buffer = malloc(sizeof(char) * 1024);

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
		
		read_total += read_cnt; /* add num of bytes last read to total */

		if (read_cnt) /* if new text read */
		{
			read_total += read_cnt; /* add num of bytes last read to total */

			/* reallocate line to receive new text */
			*line = _realloc(*line, (sizeof(char) * read_total));
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
 * main - The main function called after command line input
 */
void main(void)
{
	char *line;
	size_t line_size = 0;
	char **tok_array;

	/* print command prompt */
	write(1, "$ ", 2);

	/* read command line */
	_getline(&line, &line_size, STDIN_FILENO);

	/* set 2D array to parsed command line */
	tok_array = _strtok();

	/* execute command line */
	_execute();
}
