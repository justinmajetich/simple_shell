#include "shell.h"

/**
* _strlen - Function that finds the length of a string
* @s: string that the length of is found
*
* Return: length of s, 0 if s is NULL
*/
size_t _strlen(char *s)
{
	/* variable to loop through string to get length */
	size_t len = 0;

	if (s) /* if NULL pointer, return 0 */
		while (s[len] != '\0') /* Loop string til null byte */
			len++;

	return (len);
}
/**
 * *_strncpy - copies n bytes of src to dest string
 * @dest: string to copy to
 * @src: string to copy from
 * @n: number of bytes of src to copy
 *
 * Return: string copied to i.e dest
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		if (src[i] == '\0')
			break;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

