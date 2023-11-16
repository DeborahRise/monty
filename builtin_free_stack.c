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
	fclose(global_var.fp);
	free(global_var.buffer);
}

/**
 * free_all_global - wipes out all the memory and closes all opened files
 * Return: void
 */
void free_all_global(void)
{
	if (global_var.buffer)
	{
		free(global_var.buffer);
		global_var.buffer = NULL;
	}
	fclose(global_var.fp);
}
