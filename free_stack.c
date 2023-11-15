#include "monty.h"

/**
 * free_stack - free a linked list stack.
 * @stack: pointer to the first element of the list
 * Return: no return
 */
void free_stack(stack_t *stack)
{
	stack_t *aux = NULL;
	stack_t *temp = NULL;

	temp = stack;
	while (temp != NULL)
	{
		aux = temp->next;
		free(temp);
		temp = aux;
	}
	stack = NULL;
}

/**
 * free_glo_vars - free a global buffer.
 *
 * Return: no return
 */
void free_glo_vars(void)
{
	fclose(glo_var.fp);
	free(glo_var.buffer);
}
