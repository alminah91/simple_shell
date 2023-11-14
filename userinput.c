#include "main.h"

char *comment(void)
{
	char user[LENGTH];
	char *input_copy;
	size_t user_size = 0;
	int c;
	size_t i;

	if (fgets(user, sizeof(user), stdin) == NULL)
	{
		return NULL;
	}
	for (i = 0; i < sizeof(user); i++)
	{
		c = user[i];
		if (c == '\n' || c == '\0')
		{
			break;
		}
		user_size++;
	}
	input_copy = (char *)malloc(user_size + 1);
	if (input_copy == NULL)
	{
		return NULL;
	}
	for (i = 0; i < user_size; i++)
	{
		input_copy[i] = user[i];
	}
	input_copy[user_size] = '\0';
	return input_copy;
}
