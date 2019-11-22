#include "shell.h"
int set_path(char *name, char *value);
char *get_target(char *var_name);
/**
 * builtin_cd - change directory
 * @argv: command table
 *
 * Return: 0 on Success, -1 on Failure
 */
int builtin_cd(char *const *argv)
{
	char *target_dir = NULL;	

	/* if cd is only arg or has option "~" */
	if (argv[1] == NULL || !(_strcmp(argv[1], "~")))
	{
		/* retrieve target path */
		if ((target_dir = get_target("HOME="))) /* get home path */
		{
			if(chdir(target_dir) == -1) /* change dir */
				return (-1); /* if chdir fails */
			else
				set_path("PWD=", target_dir);
		}
		else /* if get_target returns an error */
			return (-1);
	}
	else if (path_check(&argv[1])) /* if arg is path */
	{
		if (chdir(argv[1]) == -1) /* change dir */
			return (-1); /* if chdir fails */
		else
			set_path("PWD=", argv[1]);
	}
	else if (!(_strcmp(argv[1], "."))) /* if arg is ".", change to current dir */
	{
		if ((target_dir = get_target("PWD="))) /* get cwd path */
		{
			if(chdir(target_dir) == -1) /* change dir */
				return (-1); /* if chdir fails */
			else
				set_path("PWD=", target_dir);
		}
		else /* if get_target returns an error */
			return (-1);
	}
	else
		return (-1); /* command/options not found - EERRRRRNOOOO>>>???! */
	
	return (0); /* successful change of dir */
}
/**
 * get_target - copy target path from environ
 * @var_name: name of target env variable
 *
 * Return: target path on Success, NULL on Failure
 */
char *get_target(char *var_name)
{
	char *path = NULL;
	size_t i = 0;
	size_t path_len = 0;
	size_t name_len = _strlen(var_name); /* length of var name including "=" */

	for (; environ[i]; i++) /* iterate thru environ */
	{
		/* if env variable name matches input */
		if ((_strncmp(var_name, environ[i], name_len)) == 0)
		{
			/* take length of path */
			path_len = (_strlen(environ[i]) - name_len);

			/* allocate for target path */
			path = alloc_mngr(path, (sizeof(char) * (path_len + 1)));
			if (!path) /* if malloc fail */
				return (NULL); /* return error */

			/* copy path from env to new string */
			_strncpy(path, &environ[i][name_len], path_len);

			return (path);
		}
	}
	errno = ENOENT; /* set error to f or dir not found */
	return (NULL); /* variable not found in environ */
}
/**
 * set_path - set path value of environ var (PWD/OLDPWD)
 * @name: name of variable
 * @value: desired value of variable
 *
 * Return: 0 on Success, 1 on Failure
 */
int set_path(char *name, char *value)
{
	char *update = NULL;
	size_t i = 0;
	size_t val_len;
	size_t name_len;

	val_len = _strlen(value);
	name_len = _strlen(name);

	for (; environ[i]; i++) /* iterate thru environ */
	{
		/* if env variable name matches input */
		if ((_strncmp(name, environ[i], name_len)) == 0)
		{
			/* reallocate space for updated env var */
			environ[i] = _realloc(update, (sizeof(char) * (name_len + val_len + 1)));
			if (!environ[i]) /* if malloc fail */
				return (-1);

			_strncpy(environ[i], name, name_len); /* copy var name to realloc */
			_strcat(environ[i], value); /* concat new value to realloc */

			return (0);
		}
	}

	errno = ENOENT; /* env var name not found */
	return (-1);
}
