#include "monty.h"

/**
 * swap_op - swap opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swap(stack);
}

/**
 * add_op - add opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	add(stack);
}

/**
 * sub_op - sub opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub(stack);
}

/**
 * mul_op - mul opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul(stack);
}

/**
 * div_op - div opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divide(stack);
}
