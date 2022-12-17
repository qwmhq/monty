#include "monty.h"

/**
 * printall - print all elements in a stack
 *
 * @stack: address of the stack
 */
void printall(stack_t *stack)
{
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * printall_rev - print elements in a stack in reverse order
 *
 * @stack: address of the stack
 */
void printall_rev(stack_t *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	while (stack->prev != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->prev;
	}
	printf("%d\n", stack->n);
}
