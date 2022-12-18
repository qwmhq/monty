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
 * pstr - print the string starting at the top of the stack,
 * followed by a new line
 *
 * @stack: address of the stack
 */
void pstr(stack_t *stack)
{
	stack_t *ptr = stack;

	while (ptr && ptr->n > 0 && ptr->n < 128)
	{
		putchar(ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}

/**
 * rotl - rotate the stack to the top
 *
 * @stack: address of the stack
 */
void rotl(stack_t **stack)
{
	stack_t *head = *stack, *tail = *stack;

	if (head == NULL || head->next == NULL)
		return;
	while (tail && tail->next)
		tail = tail->next;
	*stack = head->next;
	tail->next = head;
	head->prev = tail;
	head->next->prev = NULL;
	head->next = NULL;
}

/**
 * rotr - rotate the stack to the bottom
 *
 * @stack: address of the stack
 */
void rotr(stack_t **stack)
{
	stack_t *head = *stack, *tail = *stack;

	if (head == NULL || head->next == NULL)
		return;
	while (tail && tail->next)
		tail = tail->next;
	*stack = tail;
	tail->next = head;
	head->prev = tail;
	tail->prev->next = NULL;
	tail->prev = NULL;
}
