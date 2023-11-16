#include <string.h>
#include "monty.h"
#include <stdio.h>

GLOBE_STRUCT global_var = {NULL, NULL, NULL, 0};
/**
 * main - main entry point of the interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		monty_file_err();

	global_var.fp = fopen(argv[1], "r");
	if (!global_var.fp)
		fopen_err(argv[1]);

	_interpreter();

	free_all_global();
	return (EXIT_SUCCESS);
}
