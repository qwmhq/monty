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

/**
 * pstr - print the string starting at the top of the stack, followed by a new line
 *
 * @stack: address of the stack
 */
void pstr(stack_t *stack)
{
	stack_t *ptr = stack;

	while(ptr && ptr->n > 0 && ptr->n < 128)
	{
		putchar(ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}
