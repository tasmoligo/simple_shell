#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @s: the string
 * @c: the character
 * Return: found character
 */
char *_strchr(char *s, char c)
{
	int i = 0;
	int j;

	while (s[i])
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		if (c == s[j])
		{
			s += j;
			return (s);
		}
	}
	return ('\0');
}
