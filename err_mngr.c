#include "shell.h"
/**
 * print_err - print error message
 * @loop_cnt: current iteration of shell loop
 *
 *
 */
void print_err(size_t loop_cnt)
{
	char *loop_num = NULL;
	char *err_tag = NULL;

	/* allocate space to hold converted number */
	loop_num = alloc_mngr(loop_num, (sizeof(char) * (sizeof(size_t) * 4)));

	_itoa(loop_cnt, loop_num, 10); /* convert count to string */

	/* allocate for error tag (6 for string literal in next line, plus null-byte */
	err_tag = alloc_mngr(err_tag, sizeof(char) * (6 + _strlen(loop_num)));

	_strncpy(err_tag, "hsh: ", 5); /* copy string literal into error tag */

	_strcat(err_tag, loop_num); /* concatenate loop number onto tag */

	perror(err_tag); /* print error */
}
