#include "shell.h"

/**
  * _getline - reads a line from a file
  * @lineptr: a pointer to a pointer to the buffer to store the read line
  * @n: a pointer to the size of the buffer
  * @stream: a pointer to the file to read from
  *
  * Return: the number of characters read, or -11 on failure
  */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int character;
	size_t i = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*lineptr == NULL || *n == 0)
	{
		*n = SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while ((character = fgetc(stream)) != '\0')
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		(*lineptr)[i++] = (char)character;
		if (character == '\n')
		{
			break;
		}
	}
	(*lineptr)[i] = '\0';
	if (i == 0)
	{
		return (-1);
	}
	return (i);
}
