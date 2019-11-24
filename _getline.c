#include "shell.h"
/**
 * _getline - retrieve command line
 * @line: buffer to store command line
 * @line_size: length of command line
 *
 * Return: Number of lines read on success or -1 on fail
 */
ssize_t _getline(char **line)
{
	ssize_t read_cnt, read_total = 0;
	size_t offset = 0; /* line offset for each iteration */
	char buffer[1024];

	/* read stdin to dynamic buffer */
	while ((read_cnt = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
	{
		if (read_cnt == -1) /* check for read failure */
			return (-1);

		read_total += read_cnt; /* add num of bytes last read to total */

		/* reallocate line to receive new text (+ 1 for null-byte) */
		*line = alloc_mngr(*line, (sizeof(char) * (read_total + 1)));
		if (!(*line)) /* check for reallocation fail */
			return (-1);
			
		/* copy buffer to line from current offset */
		_strncpy(((*line) + offset), buffer, read_cnt);

		offset = read_total; /* advance line offset */

		/* if line is \n terminated */
		if ((*line)[offset - 1] == '\n')
		{
			(*line)[offset - 1] = '\0'; /* null-terminate line */
			break; /* break read loop */
		}
	}

	return (read_total); /* return total number of bytes read */
}
