#include "shell.h"

/**
* process_user_input - processes the user input
* and passes it to the appropriate function
* @input: the user's input
* Return: nothing
*/

void process_user_input(char *input)
{
	char *executable_path;
	char **tokens = parse_command(input);
	int i, j;

	if (tokens[0] != NULL)
	{
		int i = 0;

		while (builtins[i].name != NULL)
		{
			if (strcmp(tokens[0], builtins[i].name) == 0)
			{
				builtins[i].function(tokens);
				for (j = 0; tokens[j] != NULL; j++)
				{
					free(tokens[j]);
				}
				free(tokens);
				return;
			}
			i++;
		}
	}
	executable_path = find_executable(tokens[0]);
	if (executable_path != NULL)
	{
		execute_command(executable_path, tokens);
		free(executable_path);
	}
	else
	{
		printf("%s: No such file or directory\n", tokens[0]);
	}
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
