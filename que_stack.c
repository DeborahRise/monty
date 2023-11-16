#include "monty.h"

/**
 * create_stack - create a stack.
 * @stack: A pointer to top and bottom stack.
 * Return: EXIT SUCCESS
 */
int create_stack(stack_t **stack)
{
	stack_t *p;

	p = malloc(sizeof(stack_t));
	if (p == NULL)
		malloc_err();
	p->n = STACK;
	p->prev = NULL;
	p->next = NULL;

	*stack = p;

	return (EXIT_SUCCESS);
}
/**
 * free_stacknode - Frees a stack_t stack.
 * @stack: A pointer to top and bottom stack.
 */
void free_stacknode(stack_t **stack)
{
	stack_t *temp_node = *stack;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;
	}
}

/**
 * _STACK - a func that switches mode to stack
 * @stack: stack head
 * @line_number: line_number
 * Return: void
 */
void _STACK(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_var.mode = 0;
}

/**
 * _QUEUE - a func that switches mode to stack
 * @stack: stack head
 * @line_number: line_number
 * Return: void
 */

void _QUEUE(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_var.mode = 1;
}
