#include "shell.h"

/**
 * normal_out - Normal exit function
 * @m: Copy of environmental variables
 * @e: Number of elements in m
 */
void normal_out(char **m, int e)
{
    free_grid(m, e);
    exit(current_status(NULL));
}

/**
 * double_ctrl_d_out - Exit function on double Ctrl+D
 * @m: Copy of environmental variables
 * @e: Number of elements in m
 * @line: Input of user
 */
void double_ctrl_d_out(char **m, int e, char *line)
{
    free(line);
    free_grid(m, e);
    write(STDIN_FILENO, "#cisfun$ ", 9);
    write(STDIN_FILENO, "\n", 1);
    exit(current_status(NULL));
}

/**
 * normal_out_with_newline - Normal exit function with newline
 * @m: Copy of environmental variables
 * @e: Number of elements in m
 */
void normal_out_with_newline(char **m, int e)
{
    free_grid(m, e);
    write(STDIN_FILENO, "\n", 1);
    exit(current_status(NULL));
}

/**
 * get_line - Function to read what the user writes
 * @a: Pointer to loop counter
 * @m: Copy of environmental variables
 * @e: Length of m
 * Return: Line on success; otherwise, NULL.
 */
char *_getline(int *a, char **m, int e)
{
    char letter[1] = {0}, *line = NULL;
    size_t bufsize = 0;
    static int num = 1;

    if (num == 2)
        double_ctrl_d_out(m, e, line);

    for (; (num != 0); bufsize = 0, free(line))
    {
        write(STDIN_FILENO, "#cisfun$ ", 9);
        *a = *a + 1;
        signal(SIGINT, _signal);

        for (; ((num = read(STDIN_FILENO, letter, 1)) > 0); bufsize++)
        {
            if (bufsize == 0)
                line = _calloc(bufsize + 3, sizeof(char));
            else
                line = _realloc(line, bufsize, bufsize + 3);

            if (!line)
            {
                num = 0;
                break;
            }

            line[bufsize] = letter[0], line[bufsize + 1] = '\n';
            line[bufsize + 2] = '\0';

            if (line[bufsize] == '\n')
                break;
        }

        if (num == 0 && bufsize == 0)
            break;
        else if (num == 0 && bufsize != 0)
        {
            num = 2;
            break;
        }
        else if (line[0] != '\n')
            return (line);
    }

    if (num == 0)
        normal_out_with_newline(m, e);

    return (line);
}

/**
 * get_line_with_arguments - Function to read what the user writes
 * @a: Pointer to loop counter
 * @m: Copy of environmental variables
 * @e: Length of m
 * @av: Arguments in input
 * Return: Line on success; otherwise, NULL.
 */
char *_getline_with_arguments(int *a, char **m, int e, char **av)
{
    char letter[1] = {0}, *li = NULL;
    size_t bufsize = 0;
    static unsigned int num = 1;
    static int fd;

    for (; (num != 0); bufsize = 0, free(li))
    {
        fd = open(av[1], O_RDONLY);

        if (fd == -1)
        {
            close(fd);
            free_grid(m, e);
            write(STDERR_FILENO, av[0], _strlen(av[0]));
            write(STDERR_FILENO, ": 0: ", 5);
            write(STDERR_FILENO, "Can't open ", 11);
            write(STDERR_FILENO, av[1], _strlen(av[1]));
            write(STDERR_FILENO, "\n", 1);
            exit(127);
        }

        *a = *a + 1;

        while ((num = read(fd, letter, 1)) > 0)
        {
            if (bufsize == 0)
                li = _calloc(bufsize + 3, sizeof(char));
            else
                li = _realloc(li, bufsize, bufsize + 3);

            if (!li)
            {
                num = 0;
                break;
            }

            li[bufsize] = letter[0], li[bufsize + 1] = '\n';
            li[bufsize + 2] = '\0';
            bufsize++;
        }

        if (num == 0 && bufsize == 0)
            break;
        else if (li[0] != '\n')
            return (li);
    }

    if (num == 0)
    {
        close(fd);
        normal_out(m, e);
    }

    return (li);
}

