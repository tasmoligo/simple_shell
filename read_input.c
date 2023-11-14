#include "shell.h"

/**
* read_user_input - Reads a line of input from the user
* Return: A dynamically allocated string containing
*    the user input, or NULL if an error occurs.
*/

char *read_user_input()
{
	char *input = NULL;
	size_t input_size = 0;

	if (_getline(&input, &input_size, stdin) == -1)
	{
		perror("Error reading user input");
		exit(EXIT_FAILURE);
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("error while reading the input from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
