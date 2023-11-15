#include "shell.h"

/**
* parse_command - Splits a command string into its individual tokens
* @input: The command string to parse
* Return: An array of dynamically allocated strings
*      representing the tokens of the command, or NULL
*      if an error occurs.
*/

char **parse_command(char *input)
{
	int token_count = 0;
	char *token;
	char **tokens = (char **)malloc(MAX_INPUT_SIZE * sizeof(char *));

	if (tokens == NULL)
	{
		perror("Error allocating memory for tokens");
		exit(EXIT_FAILURE);
	}
	token = _strtok(input, " \n");

	while (token != NULL)
	{
		tokens[token_count] = strdup(token);
		if (tokens[token_count] == NULL)
		{
			perror("Error allocating memory for token");
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = _strtok(NULL, " \n");
	}
	tokens[token_count] = NULL;
	return (tokens);
}
