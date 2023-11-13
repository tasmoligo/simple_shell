#include "shell.h"

/**
* interactive - Interactively runs the shell until the user exits.
*/

void interactive(void)
{
	char *input;

	while (1)
	{
		display_prompt();
		input = read_user_input();
		process_user_input(input);
		free(input);
	}
}
