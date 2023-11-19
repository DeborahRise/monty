#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define DELIM " \n\t\a\b"
#define STACK 0
#define QUEUE 1
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
 * struct some_globals - struct with variable globals
 * @int_token: integer
 * @fp: points to the previous element of the stack (or queue)
 * @buffer: points to the next element of the stack (or queue)
 * @mode: checks for the mode of entry. Queue or Stack
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct some_globals
{
	char *int_token;
	FILE *fp;
	char *buffer;
	int mode;
} GLOBE_STRUCT;

extern GLOBE_STRUCT global_var;
/* Brains of the interpreter */
void _interpreter(void);

/*error functions*/
void free_all_global(void);
void monty_file_err(void);
void malloc_err(void);
void fopen_err(char *fd);
void push_int_err(unsigned int line_number);
void unknown_cmd_err(char *token, unsigned int line_number);
void div_err(unsigned int line_number);
void op_err(unsigned int line_number, char *op);
void pop_err(unsigned int line_number);
void pint_err(unsigned int line_number);
void pchar_err(unsigned int line_number, char *msg);

/*functions for the Node*/
void free_stack(stack_t *stack);
void free_glo_vars(void);
stack_t *add_newnode(stack_t **head, int n);
stack_t *create_stacknode_front(stack_t **stack, int n);
stack_t *create_stacknode_end(stack_t **stack, int n);
void free_stacknode(stack_t **stack);

/*The op_func and other helper functions*/
int _isdigit(void);
void rotr(stack_t **stack, unsigned int line_number);
int get_op_func(const char *token, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void div_v(stack_t **stack, unsigned int line_number);
void mod_v(stack_t **stack, unsigned int line_number);
void pstr_v(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void _QUEUE(stack_t **stack, unsigned int line_number);
void _STACK(stack_t **stack, unsigned int line_number);


#endif
