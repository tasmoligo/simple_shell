#include "shell.h"

/**
* get_current_directory - Retrieves the current working directory path
* Return: A dynamically allocated string containing the
*      current working directory path, or NULL if an error occurs.
*/

char *get_current_directory(void)
{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("Error getting current directory");
		exit(EXIT_FAILURE);
	}
	return (cwd);
}

/**
* display_prompt - Displays the shell prompt with the current working directory
*/

void display_prompt(void)
{
	char *cwd = get_current_directory();

	printf("myshell%s_$ ", cwd);
	free(cwd);
}
