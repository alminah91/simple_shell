#include "main.h"

int execute_built_in_commands(char *command)
{
	if (compare_strings(command, "exit"))
	{
		exit(EXIT_SUCCESS);
	}
	else if (compare_strings(command, "env"))
	{
		system("env");
		return 1;
	}
	else if (compare_strings(command, "cd"))
	{
		const char *home_directory = getenv("HOME");
		if (home_directory != NULL)
		{
			if (chdir(home_directory) != 0)
			{
				perror("cd");
			}
		}
		return 1;
	}
	return 0;
}
