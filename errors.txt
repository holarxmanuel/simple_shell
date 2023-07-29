#include "shell.h"

/**
 * _errorcd - wri the error
 * @p: input poinr
 * Return: nothing.
 */
void _errorcd(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], 2);
	write(STDERR_FILENO, ": can't cd to ", 14);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&a);
}
/**
 * _errorexit - writesthe error
 * @p: input pointer
 * Return: nothing.
 */
void _errorexit(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], 4);
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&a);
}
/**
 * _errorhelp - writesthe error
 * @p: input pnter
 * Return: nothing.
 */
void _errorhelp(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], 4);
	write(STDERR_FILENO, ": no help topics match '", 24);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "'. Try 'help help' or 'man -k '", 31);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "' or info '", 11);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "'\n", 2);
	currentstatus(&a);
}
/**
 * _errorgarbage - writes  error
 * @p: input ponter
 * Return: nothing.
 */
void _errorgarbage(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], _strlen(p[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	currentstatus(&a);
}
/**
 * _errorenv - tes the error
 * @p: input poter
 * Return: nothng.
 */
void _errorenv(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], _strlen(p[0]));
	write(STDERR_FILENO, ": unable to add/rm variable ", 28);
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&a);
}
