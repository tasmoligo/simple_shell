#include "shell.h"

/**
  * _strtok - breaks a string into a sequence of zero
  *		or more non-empty tokens)tokenize)
  * @str: a pointer to the string to tokenize
  * @delim: a set of bytes that delimit the tokens in the parsed string
  * Return: a pointer to the next token, or NULL if there are no more tokens
  */
char *_strtok(char *str, char *delim)
{
	char *begin, *end, *toks = NULL;

	if (str != NULL)
	{
		toks = str;
	}
	else if (toks == NULL)
	{
		return (NULL);
	}
	begin = toks;
	while (*begin != '\0' && _strchr(delim, *begin) != NULL)
	{
		begin++;
	}
	if (*begin == '\0')
	{
		toks == NULL;
		return (NULL);
	}
	end = begin;
	while (*end != '\0' && _strchr(delim, *end) == NULL)
	{
		end++;
	}
	if (*end != '\0')
	{
		*end = '\0';
		toks = end + 1;
	}
	else
	{
		toks = NULL;
	}
	return (begin);
}
