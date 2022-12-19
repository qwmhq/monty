#include "monty.h"

/**
 * rotr_op - rotr opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void rotr_op(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	rotr(stack);
}

/**
 * stack_op -stack opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void stack_op(stack_t **stack __attribute__((unused)),
				unsigned int line_number __attribute__((unused)))
{
	stack_mode = 1;
}

/**
 * queue_op -queue opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void queue_op(stack_t **stack __attribute__((unused)),
				unsigned int line_number __attribute__((unused)))
{
	stack_mode = 0;
}
