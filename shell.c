#ifndef _SH
#define _SH

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


/*global variables*/

char **create_env(char *envp[]);
void updateoldpwd(char *buf, char **myenv);
void updatepwd(char *buf, char **myenv);

/*setenv*/
int issetenv(char **p, char ***myenv, int *e, int loop, char *v[]);
void setenv(char **p, char ***myenv, int *e, int loop, char *v[]);
void setenvcreat(char ***myenv, int *e, char *entirenv);

/* unsetenv*/
int isunsetenv(char **p, char **myenv, int *e, int loop, char *v[]);
void unsetenv(char **p, char **myenv, int *e, int loop, char *v[]);
void errorenv(char **p);

/* shell functions*/
void noargv(char *argv[], char *envp[]);
void yesargv(char *argv[], char *envp[]);
void functions(char *line, int loop, char *argv[], char ***m, int *e, char *f);
int rev(char **p, int L, char *li, char **v, char ***m, int *e, char *f);
char *str_concat(char *s1, char *s2);
int strlen(char *s);
void *realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char *getline(int *a, char **m, int e);
char  *getlineav(int *a, char **m, int e, char **av);
char **parsing(char *line);
char *comments(char *line);
int semicolon(char *line, int loop, char **argv);
int currentstatus(int *status);

/*char getline_av(char *buffer);*/
void free_grid(char **grid, int height);
void frk(char **p, char *l, int a, int L, char **v, int e, char **m, char *f);
void *calloc(unsigned int nmemb, unsigned int size);
char **checkbin(char **b, char **m);
void *realloc2(char *a, char *p, unsigned int old, unsigned int new_size);
int  isexit(char **p, int L, char *l, char **v, char **m, char *f);
void signal(int s);
int isenv(char **p, char **myenv);
void env(char **myenv);
void cd(char **a, int loop, char *v[], char **myenv);
int iscd(char **p, int loop, char *v[], char **myenv);
char *gethome(char **m);
char *changepwd(void);
char *changeoldpwd(void);
char *getpwd(char **m);
int atoi(char *s);
char *strtoky(char *s, char *d);
char *strtoky2(char *s, char *d);

#define SIZE 1024

/* help files*/
int ishelp(char **p, int loop, char *v[], char **m);
void help_builtin(char **p, int loop, char *v[], char **m);
void help(char **p, int loop, char *v[], char **m);
ssize_t read_help(char **m);
ssize_t read_cdhelp(char **m);
ssize_t read_exithelp(char **m);
ssize_t read_helphelp(char **m);

/* errors */
void put_err(char **p, int loop, int sig, char *v[]);
void builtinerr(char **p);
void builtinerr2(char **p);
void errorcd(char **p);
void errorexit(char **p);
void errorhelp(char **p);
void errorgarbage(char **p);
void print_number(int n);

#endif
