#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>

GLOBE_VAR glo_var = {NULL, NULL, NULL};

/**
 * main - main entry point of the interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	char *token = NULL;
	size_t buf_size = 0;
	int counter = 0, flag = 0, flag2 = 0;
	ssize_t reads;
	stack_t *stack = NULL;

	if (argc != 2)
		monty_file_err();
	glo_var.fp = fopen(argv[1], "r");
	if (!glo_var.fp)
		fopen_err(argv[1]);
	reads = getline(&glo_var.buffer, &buf_size, glo_var.fp);
	if (glo_var.buffer[0] == '#')
		reads = getline(&glo_var.buffer, &buf_size, glo_var.fp);
	while (reads >= 0)
	{flag = 0;
		flag2 = 0;
		counter++;
		token = strtok(glo_var.buffer, DELIM);
		glo_var.int_token = strtok(NULL, DELIM);
		if (token == NULL)
		{flag2 = 1;
			nop(&stack, counter); }
		if (flag2 == 0)
		{
			if (token[0] == '#')
			{
				reads = getline(&glo_var.buffer,
						&buf_size, glo_var.fp);
				flag = 1; }}
		if (flag == 0)
		{get_op_func(token, &stack, counter);
			reads = getline(&glo_var.buffer, &buf_size,
					glo_var.fp); }}
			free_stack(stack);
			free(glo_var.buffer);
			glo_var.buffer = NULL;
			fclose(glo_var.fp);
			return (EXIT_SUCCESS);
}
