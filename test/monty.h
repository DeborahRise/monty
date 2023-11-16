#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809l
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
/* Macros */
#define DELIM " "
/* aliases */
typedef unsigned int ui;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * global_values - holds all the value needed by the opcode functoins
 * @int_value: the int value to add to the stack
 *
 * Description: nothing to do here just holding values
 */
typedef struct global_values
{
	char *int_token;
} globals;

extern globals global_var;

/* you are going to add the push and pal function prototype over here */
void push(stack_t **stack, ui line_number);
void pall(stack_t **stack, ui line_number);
void execute_commands(stack_t **stack, const char *buffer, size_t counter);
#endif
