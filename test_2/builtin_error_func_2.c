#include "monty.h"

/**
 * pop_err - pop error message for empty stacks.
 * @line_number: line number of the instructions.
 * Return: EXIT_FAILURE.
 */
void pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	free_glo_vars();
	exit(EXIT_FAILURE);
}

/**
 * pint_err - pint error message for empty stacks.
 * @line_number: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_glo_vars();
	exit(EXIT_FAILURE);
}

/**
 * op_err - math func error messagess.
 * @line_number: line number of the instruction.
 * @op: Operation where the error occurred.
 * Return: EXIT_FAILURE
 */
void op_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	free_glo_vars();
	exit(EXIT_FAILURE);
}
/**
 * pchar_err - phar error msg for 0 stack & and non-char val.
 * @line_number: line number of the instruction
 * @msg: error message to print.
 * Return: EXIT_FAILURE.
 */
void pchar_err(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	free_glo_vars();
	exit(EXIT_FAILURE);
}

/**
* div_err - error for div by 0.
* @line_number: line number of the instruction.
* Return: EXIT_FAILURE
*/
void div_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_glo_vars();
	exit(EXIT_FAILURE);
}
