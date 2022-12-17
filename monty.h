#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DELIM " \n\t"

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

void (*get_opcode_func(char *))(stack_t **, unsigned int);
stack_t *push(stack_t **, int);
void printall(stack_t *);
void printall_rev(stack_t *);
void pop(stack_t **);
void swap(stack_t **);
void add(stack_t **);
void free_stack(stack_t **);
int validate_num(char *);
void push_op(stack_t **, unsigned int);
void pall_op(stack_t **, unsigned int);

#endif
