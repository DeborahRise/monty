#include "monty.h"
/**
 * monty_file_err- usage error.
 * Return: EXIT_FAILURE
 */
void monty_file_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * malloc_err - Prints malloc error messages.
 * Return: EXIT_FAILURE
 */

void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_glo_vars();
	exit(EXIT_FAILURE);
}
/**
 * fopen_err - error of fopen.
 * @filename: type pointer char of filename
 * Return: EXIT_FAILURE
 */
void fopen_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * push_int_err - error of int.
 * @line_number: type pointer of line number
 * Return: EXIT_FAILURE
 */
void push_int_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	free_glo_vars();
	exit(EXIT_FAILURE);
}

/**
 * unknown_cmd_err - unknown error messagess.
 * @line_number: line number of the instruction.
 * @token: type pointer char of the instruction.
 * Return: EXIT_FAILURE
 */
void unknown_cmd_err(char *token, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	free_glo_vars();
	exit(EXIT_FAILURE);
}
