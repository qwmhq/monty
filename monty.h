#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DELIM " \n\t"

extern int stack_mode;

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

/*stack functions*/
stack_t *push(stack_t **, int);
stack_t *pushq(stack_t **, int);
void printall(stack_t *);
void printall_rev(stack_t *);
void pop(stack_t **);
void swap(stack_t **);
void add(stack_t **);
void sub(stack_t **);
void divide(stack_t **);
void mul(stack_t **);
void mod(stack_t **);
void pchar(stack_t **);
void pstr(stack_t *);
void rotl(stack_t **);
void rotr(stack_t **);
void free_stack(stack_t **);

int validate_num(char *);
/*opcode functions*/
void (*get_opcode_func(char *))(stack_t **, unsigned int);
void push_op(stack_t **, unsigned int);
void pall_op(stack_t **, unsigned int);
void pint_op(stack_t **, unsigned int);
void pop_op(stack_t **, unsigned int);
void swap_op(stack_t **, unsigned int);
void add_op(stack_t **, unsigned int);
void nop_op(stack_t **, unsigned int);
void sub_op(stack_t **, unsigned int);
void div_op(stack_t **, unsigned int);
void mul_op(stack_t **, unsigned int);
void mod_op(stack_t **, unsigned int);
void pchar_op(stack_t **, unsigned int);
void pstr_op(stack_t **, unsigned int);
void rotl_op(stack_t **, unsigned int);
void rotr_op(stack_t **, unsigned int);
void stack_op(stack_t **, unsigned int);
void queue_op(stack_t **, unsigned int);

#endif
