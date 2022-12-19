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

/**
 * pushq - add an element to the end of a queue
 *
 * @stack: address of the stack
 * @n: the element to add
 *
 * Return: the address of the stack after adding the new element
 */
stack_t *pushq(stack_t **stack, int n)
{
	stack_t *new, *ptr = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	while (ptr && ptr->next)
		ptr = ptr->next;
	if (ptr)
	{
		ptr->next = new;
		new->prev = ptr;
	}
	else
		*stack = new;
	return (*stack);
}
