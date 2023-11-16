#include "monty.h"
/**
 * _interpreter - setting up everything for interpretation
 * Return: void
 */
void _interpreter(void)
{
	int counter = 0, flag = 0, flag2 = 0;
	ssize_t reads;
	size_t toreads = 0;
	char *token = NULL;
	stack_t *stack = NULL;

	reads = getline(&global_var.buffer, &toreads, global_var.fp);
	if (global_var.buffer[0] == '#')
		reads = getline(&global_var.buffer, &toreads, global_var.fp);
	while (reads >= 0)
	{
		flag = 0;
		flag2 = 0;
		counter++;
		token = strtok(global_var.buffer, DELIM);
		global_var.int_token = strtok(NULL, DELIM);
		if (token == NULL)
		{
			flag2 = 1;
			nop(&stack, counter);
		}
		if (flag2 == 0)
		{
			if (token[0] == '#')
			{
				reads = getline(&global_var.buffer, &toreads, global_var.fp);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			get_op_func(token, &stack, counter);
			reads = getline(&global_var.buffer, &toreads, global_var.fp);
		}
	}
	free_stack(stack);
}
