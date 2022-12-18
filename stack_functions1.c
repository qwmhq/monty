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

/**
 * sub - subtract the top element of the stack from the second top element
 *
 * @stack: address of the stack
 */
void sub(stack_t **stack)
{
	stack_t *head = *stack;

	head->next->n -= head->n;
	pop(stack);
}

/**
 * mul - multiply the top two elements of the stack
 *
 * @stack: address of the stack
 */
void mul(stack_t **stack)
{
	stack_t *head = *stack;

	head->next->n *= head->n;
	pop(stack);
}

/**
 * divide - divide the top element of the stack by the second top element
 *
 * @stack: address of the stack
 */
void divide(stack_t **stack)
{
	stack_t *head = *stack;

	head->next->n /= head->n;
	pop(stack);
}
