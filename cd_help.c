#include "shell.h"
/**
 * cd_user - move to user home
 * Return: 0 on Success, 1 on Failure
 */
int cd_user(char *argv)
{
	char *userdir = NULL;
	size_t user_len = _strlen(argv);

	userdir = alloc_mngr(userdir, (sizeof(char) * (6 + user_len)));
	if (!userdir) /* if malloc fail */
		return (-1);

	_strncpy(userdir, "/home/", 6); /* copy "/home/" to new string */
	_strcat(userdir, &argv[1]); /* concat username to dir */

	if (chdir(userdir) == 0) /* move to user home dir */
	{
		set_OLDPWD();
		set_PWD(userdir);
		 return (0);
	}

	errno = ENOENT; /* invalid username - dir not found */
	return (-1); 
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
 * set_PWD - set path value of environ var PWD
 * @name: name of variable
 * @value: desired value of variable
 *
 * Return: 0 on Success, 1 on Failure
 */
int set_PWD(char *value)
{
	char *update = NULL;
	char *name = "PWD=";
	size_t i = 0;
	size_t val_len;
	size_t name_len = 4;

	val_len = _strlen(value); /* take length of target value */
	
	for (; environ[i]; i++) /* iterate thru environ */
	{
		/* if env variable name matches input */
		if ((_strncmp(name, environ[i], name_len)) == 0)
		{
			/* reallocate space for updated env var */
			environ[i] = _realloc(update, (sizeof(char) * (name_len + val_len + 1)));
			if (!environ[i]) /* if malloc fail */
				return (-1);

			add_mem_node(&static_mem_head, environ[i]); /* add to lasting free list */

			_strncpy(environ[i], name, name_len); /* copy var name to realloc */
			_strcat(environ[i], value); /* concat new value to realloc */

			return (0);
		}
	}

	errno = ENOENT; /* env var name not found */
	return (-1);
}
/**
 * set_OLDPWD - set path value of environ var OLDPWD
 * @name: name of variable
 * @value: desired value of variable
 *
 * Return: 0 on Success, 1 on Failure
 */
int set_OLDPWD(void)
{
	char *update = NULL;
	char *pwd = NULL;
	char *owd_ref = "OLDPWD=";
	char *pwd_ref = "PWD=";
	size_t i;
	size_t pwd_len = 0;

	for (i = 0; environ[i]; i++) /* iterate thru environ for PWD */
		if ((_strncmp(pwd_ref, environ[i], 4)) == 0) /* if PWD variable found */
			pwd = &environ[i][4]; /* point to PWD value */
	if (!pwd) /* could not find PWD var */
		return (-1);

	pwd_len = _strlen(pwd); /* take length pwd path */

	for (i = 0; environ[i]; i++) /* iterate thru environ for OLDPWD */
	{
		if ((_strncmp(owd_ref, environ[i], 7)) == 0) /* if OLDPWD variable found */
		{
			/* reallocate space for updated env var */
			environ[i] = _realloc(update, (sizeof(char) * (7 + pwd_len + 1)));
			if (!environ[i]) /* if malloc fail */
				return (-1);

			add_mem_node(&static_mem_head, environ[i]); /* add to lasting free list     */

			_strncpy(environ[i], owd_ref, 7); /* copy OLDPWD var name to realloc */
			_strcat(environ[i], pwd); /* concat new value to realloc */

			return (0);
		}
	}

	errno = ENOENT; /* env var name not found */
	return (-1);
}
