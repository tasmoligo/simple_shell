#include "shell.h"

/**
* main - Entry point of the shell program
* Return: 0 on successful execution, non-zero on error
*/

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	}
	else
	{
		non_interactive();
	}
	return (0);
}
