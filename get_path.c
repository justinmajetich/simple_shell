#include "shell.h"
size_t path_len(char *path_ptr);
size_t count_paths(char *paths);

char **get_path(argv)
{
	char *path_ptr = NULL; /* pointer to PATH in environ */
	char *ref = "PATH="; /* ref to compare to */
	char **paths = NULL; /* list of possible concatenated paths */
	size_t path_cnt, i;

	while (environ[i]) /* until end of env list */
		if (_strncmp(ref, environ[i], 5) == 0) /* check for match */
		{
			path_ptr = environ[i][5]; /* assign pointer to beginnign of PATH value */	
			path_cnt = count_paths(path_ptr); /* take num of paths */

			/* allocate memory for pointer to n pointers */
			paths = (char **)alloc_mngr((char *)paths, (sizeof(char *) * path_cnt));

			for ( = 0; 

		}







}
/**
 * count_path - count paths
 * @paths: PATH line of environ
 *
 * Return: number of paths, 0 if paths NULL
 */
size_t count_paths(char *paths)
{
	size_t i, path_cnt = 0;

	if (!paths) /* if path is NULL */
		return (0);

	/* iterates to counts number of paths */
	for (i = 0; paths[i]; i++)
		if ((paths[i + 1] == ':' || paths[i + 1] == '\0')
			path_cnt++;
	
	return (path_cnt);
}
/**
* path_length - take length of current path
* @path_ptr: pointer to current path
*
* Return: length of path
*/
size_t path_len(char *path_ptr)
{
	size_t i = 0;

	if (path_ptr) /* if not NULL */
		while (path_ptr[i] != ':') /* loop unitl colon */
			i++;

	return (i); /* return length of path */
}
