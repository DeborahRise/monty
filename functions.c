#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <unistd.h>
/**
 * create_stack_node - make a new stack
 * @data: value to be stored in the linked list
 * Return: pointer to the newly create_stack node
 */
stack_t *create_stack_node(ui data)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = data;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}
/**
 * push - pushes elements on the stack
 * @stack: pointer to the top of the stack
 * @line_number: data to be inserted in the stack
 * Return: void
 */
void push(stack_t **stack, ui line_number)
{
	/* doubly linked list */
	stack_t *stack_elem = create_stack_node(line_number);
	stack_t *elements = *stack;

	if (!stack_elem)
	{
		dprintf(STDERR_FILENO, "Malloc failed\n");
		return;
	}

	if (!stack || !*stack)
	{
		(*stack) = stack_elem;
	}
	else
	{
		while (elements->next)
			elements = elements->next;
		elements->next = stack_elem;
		stack_elem->prev = elements;
	}
}
/**
 * pall - print all the elements in the stack
 * @stack: pointer to the top of the stack
 * @line_number: data to be inserted in the stack
 * Return: void
 */
void pall(stack_t **stack, ui line_number)
{
	(void)line_number;
	stack_t *current = *stack;

	if (!*stack || !stack)
		dprintf(STDERR_FILENO, "stack underflow\n");

	while (current)
	{
		dprintf(STDOUT_FILENO, "%u", current->n);
		current = current->next;
	}
}
