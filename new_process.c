#include "shell.h"

/**
* execute_command - Executes a given command with its arguments.
* @command: The command to execute.
* @args: An array of arguments to pass to the command.
*/

void execute_command(char *command, char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error forking process");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execv(command, args);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
