#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	stack_t *current2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_err(line_number, "add");
	}
	current = *stack;
	while (current->next)
	{
		current = current->next;
		i++;
		flag = 1;
	}
	current2 = *stack;
	while (j < (i - 1))
	{
		current2 = current2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_stack(*stack), op_err(line_number, "add");
	else
	{
		current2->n = current2->n + current->n;
		current2->next = NULL;
		free(current);
		current = NULL;
		return;
	}
}
/**
 * sub - subtracts the top e elem from the 2nd top element.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */

void sub(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_err(line_number, "sub");
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_stack(*stack), op_err(line_number, "sub");
	else
	{
		temp2->n = temp2->n - temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
/**
 * mul - Mul 2nd val from top stack by top elem.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_err(line_number, "mul");
		return;
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_stack(*stack), op_err(line_number, "mul");
	else
	{
		temp2->n = temp2->n * temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}

}

/**
 * pop - removes the top element of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (stack == NULL)
	{
		free_stack(*stack);
		pop_err(line_number); }
	if (*stack == NULL)
	{
		free_stack(*stack);
		pop_err(line_number); }
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
	{

		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}

/**
 * pchar - Print char at the top of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		pchar_err(line_number, "stack empty");
		return;
	}
	temp = (*stack);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->n < 0 || temp->n > 127)
	{
		pchar_err(line_number, "value out of range");
	}
	printf("%c\n", temp->n);
}
