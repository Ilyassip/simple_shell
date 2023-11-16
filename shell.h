#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>



/*constants*/
#define EXTERNAL_COMMAND 1
#define PATH_COMMAND 3
#define INTERNAL_COMMAND 2
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *@command_name: name of the command
 *struct map - a struct that maps a command name to a function 
 *@func: the function that executes the command
 */

typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

extern char **environ;
extern char *shell_name;
extern char *line;
extern char **commands;
extern int status;

/*helpers*/
void print(char *, int);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);

/*built_in*/
void env(char **);
void quit(char **);

/*helpers2*/
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/*utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/*helpers3*/
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int);
void remove_comment(char *);

/*main*/
extern void non_interactive(void);
extern void initializer(char **current_command, int type_command);

#endif /*SHELL_H*/


