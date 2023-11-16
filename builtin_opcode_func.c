#include "monty.h"

/**
 * get_op_func - Parses the instruction with the function.
 * @token: type pointer extern var char
 * @stack: type pointer node of data struct
 * @line_number: line of instructions
 * Return: Retunr the funtion
 */
int get_op_func(const char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_func[] = {
	{"push", push}, {"pall", pall},
	{"pop", pop}, {"add", add},
	{"nop", nop}, {"sub", sub},
	{"pall", pall}, {"pint", pint},
	{"swap", swap}, {"mul", mul},
	{"div", div_v}, {"pchar", pchar},
	{"mod", mod_v}, {"\n", nop},
	{" ", nop}, {"\t", nop},
	{"pstr", pstr_v}, {"rotl", rotl},
	{"rotr", rotr},
	{"queue", _QUEUE },
	{"stack", _STACK },
	{NULL, NULL}
	};
	int i = 0, flag = 0;

	if (stack == NULL || token == NULL)
		return (0);
	while (op_func[i].opcode)
	{
		if (strcmp(token, op_func[i].opcode) == 0)
		{
			flag = 1;
			op_func[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (flag == 0)
		unknown_cmd_err((char *)token, line_number);
	return (0);
}
