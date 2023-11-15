#include "monty.h"
#include <string.h>
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
	int iter = 0;
	char *buffer = NULL; /* you should definetly free this guy */
	char *delim = " ", *token = NULL, *int_token = NULL;
	stack_t *head = NULL;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

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
		token = strtok(buffer, delim);
		int_token = strtok(NULL, delim);
		if (!strcmp(token, opcodes[iter].opcode))
		{
			opcodes[iter].f(&head, (ui)atoi(int_token));
			break;
		}
		counter++;
	}
	free(buffer);
	return (0);
}
