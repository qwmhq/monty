#include "monty.h"

/**
 * mod_op - mod opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod(stack);
}

/**
 * nop_op - nop opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void nop_op(stack_t **stack __attribute__((unused)),
			unsigned int line_number __attribute__((unused)))
{}

/**
 * pchar_op - pchar opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
