#include "monty.h"

/**
 * validate_num - check if a string represents a number
 *
 * @str: the string
 *
 * Return: 1 if str represents a number, otherwise 0
 */
int validate_num(char *str)
{
	if (str == NULL || (*str != '-' && !isdigit(*str)))
		return (0);
	str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * push_op - push opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, DELIM);

	if (!validate_num(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack_mode)
		push(stack, atoi(arg));
	else
		pushq(stack, atoi(arg));
}

/**
 * pall_op - pall opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void pall_op(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	printall(*stack);
}

/**
 * pint_op - pint opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_op - pop opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack);
}
