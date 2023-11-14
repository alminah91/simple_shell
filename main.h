#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void _prompt(void);
char *comment(void);
void execute_absolute_path(char *command, char *program_name);
int split_command(char *command, char *args[], int max_args);
void write_string(int fd, const char *str);
void execute_in_path(char *command, char *program_name);
int execute_built_in_commands(char *command);
int compare_strings(char *str1, char *str2);
char *_getline(void)

extern char **environ;

#define LENGTH 1024
#define MAX_ARGS 100
#define BUFFER_SIZE 1024
#define MAX_ARG_LENGTH 100

#endif
