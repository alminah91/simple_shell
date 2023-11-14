#include "main.h"

char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int pos = 0;
	static int len = 0;
	char *line = NULL;
	int line_size = 0;
	while (1)
	{
		if (pos >= len)
		{
			len = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (len <= 0)
			{
				if (line_size > 0)
				{
					line[line_size] = '\0';
					return line;
				}
				else
				{
					return NULL;
				}
			}
			pos = 0;
		}
		char current_char = buffer[pos++];
		if (current_char == '\n' || current_char == EOF)
		{
			if (line == NULL)
			{
				line = (char *)malloc(line_size + 1);
			}
			else
			{
				line = (char *)realloc(line, line_size + 1);
			}
			if (line == NULL)
			{
				fprintf(stderr, "Memory allocation error\n");
				exit(EXIT_FAILURE);
			}
			line[line_size] = '\0';
			return line;
		}
		else
		{
			if (line == NULL)
			{
				line = (char *)malloc(line_size + 1);
			}
			else
			{
				line = (char *)realloc(line, line_size + 1);
			}
			if (line == NULL)
			{
				fprintf(stderr, "Memory allocation error\n");
				exit(EXIT_FAILURE);
			}
			line[line_size++] = current_char;
		}
	}
}
