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
	(void)stack;
	(void)line_number;
	printf("push function call\n");
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
	printf("pall function call\n");
}
