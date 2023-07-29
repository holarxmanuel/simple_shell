#include "shell.h"
/**
 * currentstatus - gecurrent status
 * @status: get tpointer to the value inside  wait
 * Return: the acl changed
 */
int currentstatus(int *status)
{
	static int actual;

	if (status)
		actual = *status;
	return (actual);
}
/**
 * _frk - prot creates process and execute
 * @p: ay of pointer (args)
 * @l: it typed by the user
 * @a: cf pointers
 * @L: cof loops
 * @v: arguments in input
 * @e: e length
 * @m: cy of environmental variable
 * @f: cplete input
 * Return: Nothing.
 */

void _frk(char **p, char *l, int a, int L, char **v, int e, char **m, char *f)
{
	pid_t child_pid;
	int ty = 0, status, exist, execute;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(127);
	}
	if (child_pid == 0)
	{
		if (execve(p[0], p, m) == -1)
		{
			exist = access((const char *) p[0], F_OK);
			execute = access((const char *) p[0], X_OK);
			if (exist == 0 && execute == -1)
			{
				_put_err(p, L, 4, v);
				free(f), free(l);
				free_grid(p, a), free_grid(m, e);
				exit(126);
			}
			else
			{
				_put_err(p, L, 3, v);
			}
			free(f), free(l);
			free_grid(p, a), free_grid(m, e);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			ty = WEXITSTATUS(status);
			currentstatus(&ty);
		}
	}
}
