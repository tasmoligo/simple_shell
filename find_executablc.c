#include "shell.h"

/**
* find_executable - Searches for the executable file for a given command
* @command: The name of the command to search for.
* Return: The full path to the executable file
*      or NULL if the executable is not found.
*
*/

char *find_executable(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = _strtok(path_copy, ":");

	if (access(command, F_OK | X_OK) == 0)
	{
		return (strdup(command));
	}
	while (path_token != NULL)
	{
		char executable_path[MAX_INPUT_SIZE];

		snprintf(executable_path, sizeof(executable_path),
				"%s/%s", path_token, command);
		if (access(executable_path, F_OK | X_OK) == 0)
		{
			free(path_copy);
			return (strdup(executable_path));
		}
		path_token = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
