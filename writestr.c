#include "main.h"

void write_string(int fd, const char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}
