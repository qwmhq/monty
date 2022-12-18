#include "monty.h"

/**
 * mod - mod the top element of the stack by the second top element
 *
 * @stack: address of the stack
 */
void mod(stack_t **stack)
{
	stack_t *head = *stack;

	head->next->n %= head->n;
	pop(stack);
}
