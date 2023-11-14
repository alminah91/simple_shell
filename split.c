#include "main.h"

int split_command(char *command, char *args[], int max_args)
{
	int arg_count = 0;
	char *start = command;
	char *end = start;
	char *arg = args[arg_count];

	while (*end != '\0' && arg_count < max_args)
	{
		while (*start == ' ')
		{
			start++;
		}
		end = start;
		while (*end != '\0' && *end != ' ')
		{
			end++;
		}
		if (start != end)
		{
			args[arg_count] = (char *)malloc(end - start + 1);
			if (args[arg_count] == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			while (start != end)
			{
				*arg++ = *start++;
			}
			*arg = '\0';
			arg_count++;
		}
		start = end;
	}
	args[arg_count] = NULL;
	return arg_count;
}
