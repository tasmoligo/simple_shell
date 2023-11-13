#include "shell.h"

/**
* non_interactive - Runs the shell in non-interactive mode
*	reading commands from standard input
*	and executing them without user interaction.
*/

void non_interactive(void)
{
	char *input;

	while (1)
	{
		input = read_user_input();
		process_user_input(input);
		free(input);
	}
}
