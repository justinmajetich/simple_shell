#include "shell.h"
/**
 *
 *
 *
 *
 *
 */
int exec_mngr(char *const *argv)
{
	int r_val;

	r_val = exec_builtin(argv); /* search and execute built-in */
	if (r_val == 0) /* execution success */
		return (0);

	r_val = (exec_external(argv); /* search and execute external cmd */
	if (r_val == 0) /* execution success */
		return (0);

	perror(argv[0]); /* print cmd name */
	return (-1); /* return error */
}
/**
 */
int exec_builtin(char *const *argv)
{
	built_in fps[] = { /* stores func pointers to built-in commands */
		{"exit", builtin_exit},
		{NULL, NULL}
	};

	int i;
	int (*built_in_fp)(char *const *argv); /* func pointer prototype */

	/* compare args to built-ins */
	for (i = 0; fps[i].cmd; i++) /* iterate till NULL */
		if ((_strcmp(argv[0], fps[i].cmd)) == 0) /* if strings match */
		{
			built_in_fp = fps[i].fp; /* assign func pointer */

			if ((built_in_fp(argv)) == 0) /* execute built-in */
				return (0); /* success */
			else
				return (-1); /* error */
		}
	errno = ENOENT; /* no such file of dir */
	return (-1); /* command not found */
}
/**
 */
int exec_external(char *const *argv)
{
	char **path = NULL; /* array of paths */
	pid_t pid; /* process ID */
	int status, i; /* monitor child state changes */

	path = get_path(argv); /* retrieve separated, concat paths */

	for (i = 0; path[i]; i++) /* for every path */
		if (access(path[i], (R_OK | X_OK)) == 0) /* check for existence and exec perm */
		{
			switch ((pid = fork())) /* fork current process */
			{
				case -1: /* fork failure */
					perror(argv[0]);
					return (-1);
				case 0: /* returned to child */
					execve(path[i], argv, env); /* execute cmd */
					perror(argv[0]); /* on exec fail */
					exit(EXIT_FAILURE); /* exits child, not parent ???? */
				default: /* returned to parent */
					if ((waitpid(pid, &status, 0)) == -1)
						return (-1); /* wait failure */
					else
						return (0); /* success */
			}
		}
	return (-1); /* file/dir not found */
}
/**
 */
char **get_path()
{
}
