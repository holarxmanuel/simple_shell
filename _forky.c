#include "shell.h"
/**
 * currentstatus - get he current status
 * @status: get the pinter to the value inside  wait
 * Return: the actualchanged
 */
int currentstatus(int *status)
{
	static int actual;

	if (status)
		actual = *status;
	return (actual);
}
/**
 * frk - progrm that creates process and execute
 * @p: array ofpointer (args)
 * @l: input tyed by the user
 * @a: count ofpointers
 * @L: count ofloops
 * @v: argument in input
 * @e: env lengh
 * @m: copy of nvironmental variable
 * @f: completeinput
 * Return: Nothng.
 */

void frk(char **p, char *l, int a, int L, char **v, int e, char **m, char *f)
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
				put_err(p, L, 4, v);
				free(f), free(l);
				free_grid(p, a), free_grid(m, e);
				exit(126);
			}
			else
			{
				put_err(p, L, 3, v);
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
