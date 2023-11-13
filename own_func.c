#include "shell.h"
/**
* read_stream - Reads a line of text from a file stream
* @file: The file stream to read from.
* Return: A dynamically allocated string containing the read line
*      or NULL if the end of file is reached.
*/

char *read_stream(FILE *file)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = fgetc(file); /* read char from file stream */
		if (character == EOF)
		{
			free(line);
			return (NULL);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
		{
			line[i] = character;
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
