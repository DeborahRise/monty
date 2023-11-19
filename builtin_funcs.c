#include "monty.h"
#include <stdio.h>
#include <limits.h>

/**
 * _isdigit - Entry point
 *
 * Return: if is digit  or not, return 1 else 0
 */
int _isdigit(void)
{
	int i = 0;

	if (global_var.int_token[0] == '-' || global_var.int_token[0] == '+')
		i++;
	while (global_var.int_token)
	{
		if ((global_var.int_token[i] >= '0' && (global_var.int_token[i + 1] >= '0'
						|| global_var.int_token[i + 1] == '\0')) &&
				(global_var.int_token[i] <= '9' && (global_var.int_token[i + 1] <= '9'
													|| global_var.int_token[i + 1] == '\0')))
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

/**
 * push - Add node to the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{

	int n = 0, i = 0;
	char *endptr;

	if (global_var.int_token == NULL)
	{
		free_stack(*stack);
		push_int_err(line_number);
	}
	if (!_isdigit() || stack == NULL)
	{
		free_stack(*stack);
		push_int_err(line_number);
	}
	i = strtol(global_var.int_token, &endptr, 10);

	if (endptr == global_var.int_token ||
			*endptr != '\0' || i < INT_MIN || i > INT_MAX)
	{
		free_stack(*stack);
		push_int_err(line_number);
	}
	n = atoi(global_var.int_token);
	if (*stack  == NULL)
	{
		create_stacknode_front(stack, n);
	}
	else
	{
		create_stacknode_end(stack, n);
	}

	if (global_var.mode == 1 && (*stack)->next != NULL)
		rotl(stack, line_number);
}

/**
 * pall - Print the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_number != 1)
	{
		free_stack(*stack);
		free_glo_vars();
		exit(EXIT_SUCCESS);
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->prev;
	}
}

/**
 * pint - Print the value at the top of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pint(stack_t **stack, unsigned int line_number)
{

	stack_t *current = NULL;

	if (stack == NULL || *stack == NULL)
	{
		pint_err(line_number);
		return;
	}
	current = *stack;
	while (current->next)
		current = current->next;

	printf("%d\n", current->n);
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i, j;

	if (*stack == NULL || stack == NULL)
		op_err(line_number, "swap");

	temp = (*stack)->next;
	if (!(*stack)->next)
		op_err(line_number, "swap");
	while (temp->next)
		temp = temp->next;
	i = temp->n;
	j = temp->prev->n;
	temp->n = j;
	temp->prev->n = i;
}
