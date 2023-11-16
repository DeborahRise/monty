#include "monty.h"
#include <complex.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

globals global_var = {NULL};
/**
 * main - main entry point of the interpreter.
 * @ac: argument count.
 * @av: argument vector.
 * Return: 0 success, 1 fail
 */
int main(int ac, char **av)
{
	FILE *fp;
	size_t reads = 0, toread = 0, counter = 1; /* line number */
	stack_t **stack = NULL;
	char *buffer = NULL; /* you should definetly free this guy */

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((reads = getline(&buffer, &toread, fp) != -1))
	{
		execute_commands(stack, buffer, counter);
		counter++;
	}
	free(buffer);
	fclose(fp);
	return (0);
}
/**
 * execute_commands - just collects the commands from another file then runs it
 * @stack: pointer to the top of the stack
 * @buffer: pointer to the collected command
 * @counter: holding the line number of the current command
 * Return: void
 */
void execute_commands(stack_t **stack, const char *buffer, size_t counter)
{
	char *token = NULL;
	int iter = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	token = strtok((char *)buffer, DELIM);
	global_var.int_token = strtok(NULL, DELIM);

	while (opcodes[iter].opcode != NULL)
	{
		if (!strcmp(token, opcodes[iter].opcode) || !global_var.int_token)
		{
			opcodes[iter].f(&(*stack), counter);
		}
		iter++;
	}
}
