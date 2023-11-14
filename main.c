#define _POSIX_C_SOURCE 200809l
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - main entry point of the interpreter.
 * @ac: argument count.
 * @av: argument vector.
 * Return: 0 success, 1 fail
 */
int main(int ac, char **av)
{
	/**
	 * first open and read the file
	 * use FILE *fp = fopen()
	 * tokenize -> the command while collecting only the first tokenize
	 * use the function pointer to select the correct code
	 */
	FILE *fp;
	size_t reads = 0;
	size_t toread = 0;
	size_t counter = 1; /* line number */
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
	/* get the line */
	while ((reads = getline(&buffer, &toread, fp) != -1))
	{
		if (reads == 0)
		{
			dprintf(STDERR_FILENO, "EOF\n");
			exit(EXIT_FAILURE);
		}
		printf("[%ld] -> %s", counter, buffer);
		counter++;
	}
	free(buffer);
	return (0);
}
