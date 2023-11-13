#include "shell.h"


/* Implement built-in functions */

/**
* exit_shell - Exits the shell
* Parameters:
* @args: An array of arguments passed to the function.
* Returns:  None.
*/

void exit_shell(char **args)
{
	(void)args;
	exit(0);
}

/**
* print_environment - Prints the environment variables.
* @args: An array of arguments passed to the function.
* Returns: None.
*
*/
void print_environment(char **args)
{
	char **env;
	(void)args;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

/**
* change_directory - Changes the current working directory.
* @args: An array of arguments passed to the function.
* Returns: None.
*/

void change_directory(char **args)
{
	char *new_dir = NULL;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		char *home_dir = getenv("HOME");

		if (home_dir != NULL)
			new_dir = strdup(home_dir);
		else
		{
			return;
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		char *prev_dir = getenv("OLDPWD");

		if (prev_dir != NULL)
			new_dir = strdup(prev_dir);
		else
			return;
	}
	else
		new_dir = strdup(args[1]);
	if (chdir(new_dir) == -1)
	{
		perror("Error changing directory");
	}
	else
	{
		char *current_dir = getcwd(NULL, 0);

		if (current_dir != NULL)
		{
			setenv("PWD", current_dir, 1);
			setenv("OLDPWD", new_dir, 1);
			free(current_dir);
		}
	}
	free(new_dir);
}

/**
* struct BuiltInCommand - List of built-in commands
* @exit_shell: Exit shell
* @print_environment: Print environment
* @change_directory: changed directory
*/

struct BuiltInCommand builtins[] = {
	{"exit", exit_shell},
	{"env", print_environment},
	{"cd", change_directory},
	{NULL, NULL}
};
