#include "shell.h"
/**
 * _yesargv - shel form without filename at input
 * @argv: argument in the input
 * @envp: environmnt variables
 */
void yesargv(char *argv[], char *envp[])
{
	char *line = NULL, **m = NULL, *p = NULL, *pr1 = NULL;
	int e = 0, *ploop, i, sem;
	static int loop;

	loop = 0;
	ploop = &loop;
	while (1)
	{
		if (loop == 0)
		{
			m = create_env(envp);
			for (e = 0; m[e] != NULL; e++)
				;
		}
		line = getlineav(ploop, m, e, argv);
		sem = semicolon(line, loop, argv);
		if (!(sem == 1))
		{
			p = strtoky2(line, ";\n");
			while (p)
			{
				pr1 = calloc(strlen(p) + 2, sizeof(char));
				for (i = 0; p[i] != '\0'; i++)
					pr1[i] = p[i];
				pr1[i] = '\n';
				pr1[i + 1] = '\0';
				functions(pr1, loop, argv, &m, &e, line);
				p = strtoky2(NULL, ";\n");
			}
		}
		free(line);
	}
}
