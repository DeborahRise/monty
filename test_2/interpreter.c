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

	while ((reads = getline(&global_var.buffer, &toreads, global_var.fp)) != -1)
	{
		token = strtok(global_var.buffer, DELIM);
		global_var.int_token = strtok(NULL, DELIM);
		if (!token)
		{
			flag2 = 1;
			nop(&stack, counter); /* do nothing */
		}
		if (flag2 == 0) /* check for comment */
		{
			if (token[0] == '#')
				continue;
		}
		if (flag == 0)
			get_op_func(token, &stack, counter);
	}
	free_stack(stack);
}
