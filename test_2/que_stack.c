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
 * opcode_check - checks if STACK or QUEUE.
 * @stack: A pointer to top and bottom stack.
 * Return: The value of Stack or Queue
 */
int opcode_check(stack_t *stack)
{
	int ret_val = 2;

	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (ret_val);
}
