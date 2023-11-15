#include "monty.h"

/**
 * get_op_func - Parses the instruction with the function.
 * @token: type pointer extern var char
 * @stack: type pointer node of data struct
 * @line_number: line of instructions
 * Return: Retunr the funtion
 */
int get_op_func(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_func[] = {
		{ "push", push },
		{ "pall", pall},
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "mul", mul },
		{ "div", div_v },
		{ "pchar", pchar },
		{ "mod", mod_v },
		{ "\n", nop },
		{ " ", nop },
		{ "\t", nop },
		{ "pstr", pstr_v },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ NULL, NULL }
	};
	int i, flag = 0;
	char *param = NULL;

	if (stack == NULL || token == NULL)
		return (0);
	param = token;
	for (i = 0; op_func[i].opcode; i++)
	{
		if (strcmp(param, op_func[i].opcode) == 0)
		{
			flag = 1;
			op_func[i].f(stack, line_number);
			break;
		}
	}
	if (flag == 0)
		unknown_cmd_err(token, line_number);
	return (0);
}
