#include "main.h"

void execute_absolute_path(char *command, char *program_name)
{
	int status;
	int exit_status = WEXITSTATUS(status);
	pid_t pid = fork();
	if (pid < 0)
	{
		 perror("fork");
		 exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		
		char **args = malloc(2 * sizeof(char *));
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		args[0] = command;
		args[1] = NULL;
		execv(command, args);
		write_string(STDERR_FILENO, program_name);
		write_string(STDERR_FILENO, ": ");
		write_string(STDERR_FILENO, command);
		write_string(STDERR_FILENO, ": command not found\n");
		free(args); 
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (exit_status != 0)
			{
				write_string(STDERR_FILENO, program_name);
				write_string(STDERR_FILENO, ": ");
				write_string(STDERR_FILENO, command);
				write_string(STDERR_FILENO, ": exited with status ");
				write_string(STDERR_FILENO, "\n");
			}
		}
	}
}

