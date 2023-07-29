#include "shell.h"

/**
 * read_help - reads all text file and prints it to POSIX stdout
 * @m: copy of environmenbles
 * Return: number of lettwrite, otherwise 0.
 */

ssize_t read_help(char **m)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] = "/simple_shell/_helpfiles/help_all.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return (r);
}

/**
 * read_cdhelp - reads cdfile and prints it to POSIX stdout
 * @m: copy of environmenriables
 * Return: number of lettto write, otherwise 0.
 */

ssize_t read_cdhelp(char **m)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] = "/simple_shell/_helpfiles/help_cd.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return (r);
}

/**
 * read_exithelp - reads text file and prints it to POSIX stdout
 * @m: copy of environmenariables
 * Return: number of lettto write, otherwise 0.
 */

ssize_t read_exithelp(char **m)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] = "/simple_shell/_helpfiles/help_exit.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return (r);
}

/**
 * read_helphelp - reads text file and prints it to POSIX stdout
 * @m: copy ofvironment variables
 * Return: numr of letters to write, otherwise 0.
 */

ssize_t read_helphelp(char **m)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] = "/simple_shell/_helpfiles/help_help.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return (r);
}
