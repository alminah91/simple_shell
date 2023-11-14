#include "main.h"

void _prompt(void)
{
	const char prompt[] = "$ ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}
