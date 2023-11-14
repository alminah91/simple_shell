#include "main.h"

int main(int argc, char *argv[])
{
	char *user;
	int i;
	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] == '/')
			{
				execute_absolute_path(argv[i], argv[0]);
			}
			else
			{
				execute_in_path(argv[i], argv[0]);
			}
		}
	}
	else
	{
		while (1)
		{
			_prompt();
			user = comment();
			if (user == NULL)
			{
				exit(EXIT_FAILURE);
			}
			if (execute_built_in_commands(user))
			{
				free(user);
				continue;
			}
			if (user[0] == '/')
			{
				execute_absolute_path(user, argv[0]);
			}
			else
			{
				execute_in_path(user, argv[0]);
			}
			free(user);
		}
	}
	return 0;
}
