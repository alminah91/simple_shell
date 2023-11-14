#include "main.h"

void execute_in_path(char *command, char *program_name)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	char *full_command = NULL;
	int command_found = 0;
	char pid_str[16];
	int i = 0;
	pid_t pid = getpid();
	while (dir != NULL)
	{
		char *f;
		full_command = malloc(MAX_ARG_LENGTH);
		if (full_command == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		f = full_command;
		while (*dir)
		{
			*f++ = *dir++;
		}
		*f++ = '/';
		while (*command)
		{
			*f++ = *command++;
		}
		*f = '\0';
		if (access(full_command, X_OK) == 0)
		{
			execute_absolute_path(full_command, program_name);
			command_found = 1;
			free(full_command);
			free(path_copy);
			return;
		}
		free(full_command);
		dir = strtok(NULL, ":");
	}
	if (!command_found)
	{
		write_string(STDERR_FILENO, program_name);
		write_string(STDERR_FILENO, ": ");
		while (pid > 0)
		{
			pid_str[i++] = '0' + (pid % 10);
			pid /= 10;
		}
		while (i > 0)
		{
			write(STDERR_FILENO, &pid_str[i - 1], 1);
			i--;
		}
		write_string(STDERR_FILENO, ": ");
		write_string(STDERR_FILENO, command);
		write_string(STDERR_FILENO, ": not found in PATH\n");
		free(path_copy);
	}
}
