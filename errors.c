#include "shell.h"

/**
 * _errorcd - writs the error
 * @p: inputpointer
 * Return: nthing.
 */
void errorcd(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], 2);
	write(STDERR_FILENO, ": can't cd to ", 14);
	write(STDERR_FILENO, p[1], strlen(p[1]));
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&a);
}
/**
 * _errorexit - wrtes the error
 * @p: input pinter
 * Return: noting.
 */
void errorexit(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], 4);
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, p[1], strlen(p[1]));
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&a);
}
/**
 * errorhelp - writs the error
 * @p: input pinter
 * Return: noting.
 */
void errorhelp(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], 4);
	write(STDERR_FILENO, ": no help topics match '", 24);
	write(STDERR_FILENO, p[1], strlen(p[1]));
	write(STDERR_FILENO, "'. Try 'help help' or 'man -k '", 31);
	write(STDERR_FILENO, p[1], strlen(p[1]));
	write(STDERR_FILENO, "' or info '", 11);
	write(STDERR_FILENO, p[1], strlen(p[1]));
	write(STDERR_FILENO, "'\n", 2);
	currentstatus(&a);
}
/**
 * errorgarbage - writes the error
 * @p: inpu pointer
 * Return: othing.
 */
void errorgarbage(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], strlen(p[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	currentstatus(&a);
}
/**
 * errorenv - writes the error
 * @p: input poiter
 * Return: nothig.
 */
void errorenv(char **p)
{
	int a = 2;

	write(STDERR_FILENO, p[0], strlen(p[0]));
	write(STDERR_FILENO, ": unable to add/rm variable ", 28);
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&a);
}
