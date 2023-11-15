#ifndef SHELL_H_
#define SHELL_H_

/* Include Header file*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#include <limits.h>

#define MAX_INPUT_SIZE 1024
#define SIZE 128
extern char **environ;


/**
* struct BuiltInCommand - Represents a built-in command in the shell
* Description:
* @name: The name of the command
* @function: A pointer to the function that implements the command
*/

struct BuiltInCommand
{
	const char *name;
	void (*function)(char **args);
};

extern struct BuiltInCommand builtins[];

/* Include the prototype */
void display_prompt(void);
char *read_user_input(void);
void execute_command(char *command, char *args[]);
char *find_executable(char *command);
char **parse_command(char *input);
void process_user_input(char *input);
char *get_current_directory();
void comsep(char *args[]);
void interactive(void);
char *read_stream(FILE *file);
void non_interactive(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strchr(char *s, char c);
char *_strtok(char *str, char *delim);

/* Prototypes for built-in functions */
void exit_shell(char **args);
void print_environment(char **args);
void change_directory(char **args);

#endif /* SHELL_H_ */
