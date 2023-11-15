#include "monty.h"

/**
 * create_stacknode_front - create a node stack.
 * @stack: A pointer to top and bottom stack.
 * @n: the value
 * Return: the node
 */
stack_t *create_stacknode_front(stack_t **stack, int n)
{
	stack_t *newnode_stack;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		malloc_err();
	newnode_stack->n = n;
	newnode_stack->next = *stack;
	newnode_stack->prev = NULL;
	*stack = newnode_stack;
	return (newnode_stack);
}

/**
 * create_stacknode_end - create a node stack at end.
 * @stack: A pointer to top and bottom stack.
 * @n: the value
 * Return: the node
 */
stack_t *create_stacknode_end(stack_t **stack, int n)
{
	stack_t *newnode_stack;
	stack_t *temp;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		malloc_err();
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode_stack;
	newnode_stack->n = n;
	newnode_stack->prev = temp;
	newnode_stack->next = NULL;
	return (newnode_stack);
}
/**
 * add_newnode - adds a new node at the beginning of a dlistint_t list.
 * @head: pointer to the first element of the list
 * @n:integer
 * Return: the pointer to a new node at the beginning of a dlistint_t list
 */
stack_t *add_newnode(stack_t **head, int n)
{
	stack_t *newnode = NULL;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	if (*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return (newnode);
	}
	newnode->n = n;
	(*head)->prev = newnode;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}