#include "shell.h"

char **mal_sin_tok(char *line);
size_t count_tokens(char *line);
size_t token_length(char *line, size_t tok_need);

/**
 * **_strtok - Sets up a 2D array by parsing a string
 * @line: The string to be parsed into tokens
 *
 * Return: Always the 2D array
 */
char **_strtok(char *line)
{
	size_t t_end = 0, i = 0, j = 0, l_start = 0;
	size_t tok_amnt = count_tokens(line);
	size_t tok_len = 0, tok_curr = 1;
	char **list;

	if (tok_amnt == 1)
		list = mal_sin_tok(line);
	else
	{
		list = malloc((tok_amnt + 1) * sizeof(char *));
		if (list == NULL)
		{
			printf("There was a malloc fail");
			exit(EXIT_FAILURE);
		}

		for (i = tok_curr - 1; tok_curr <= tok_amnt; tok_curr++, i++)
		{
			tok_len = token_length(line, tok_curr);

			list[i] = malloc((tok_len + 1) * sizeof(char));
			if (list[i] == NULL)
			{
				for (i = 0; i < tok_curr; i++)
					free(list[i]);
				free(list);
				printf("There was a malloc fail.");
				exit(EXIT_FAILURE);
			}

			t_end += tok_len;

			for (j = 0; l_start < t_end; j++, l_start++)
				list[i][j] = line[l_start];

			list[i][j] = '\0';
			l_start++;
			t_end++;

		}

		list[i] = NULL;
	}
	return (list);
}
/**
 * **mal_sin_tok - A hard-coded version of a single token
 * @line: The string to add to the 2D array
 *
 * Return: Always the 2D array
 */
char **mal_sin_tok(char *line)
{
	size_t i = 0;
	size_t tok_len = _strlen(line);
	char **list = malloc(2 * sizeof(char *));

	if (list == NULL)
		return (NULL);

	list[0] = malloc((tok_len + 1) * sizeof(char));
	if (list[0] == NULL)
	{
		free(list[0]);
		free(list);
	}

	for (i = 0; i < tok_len; i++)
		list[0][i] = line[i];

	list[0][i] = '\0';
	list[1] = NULL;

	return (list);
}

/**
 * count_tokens - Counts the amount of tokens
 * @line: The string to count how many tokens it has
 *
 * Return: Always the amount of tokens
 */
size_t count_tokens(char *line)
{
	size_t i, tok_amnt = 1;

	for (i = 0; line[i] != '\0'; i++)
		if (line[i] == ' ')
			tok_amnt++;

	return (tok_amnt);
}

/**
 * token_length - Count how long a specified token is
 * @line: The string containing the token
 * @tok_need: Specifying which token length is needed
 *
 * Return: Always the length of the specified token
 */
size_t token_length(char *line, size_t tok_need)
{
	size_t i = 0, tok_len = 0, tok_curr = 1;

	for (i = 0; tok_curr <= tok_need; i++)
	{
		if (line[i] == ' ' || line[i] == '\0')
		{
			tok_curr++;
			i++;
		}

		if (tok_curr == tok_need)
			tok_len++;
	}

	return (tok_len);
}
