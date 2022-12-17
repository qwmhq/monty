#include "monty.h"

/**
 * push - add an element to the top of a stack
 *
 * @stack: address of the stack
 * @n: the element to add
 *
 * Return: the address of the stack after adding the new element
 */
stack_t *push(stack_t **stack, int n)
{
	stack_t *new, *head = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = head;
	if (head)
		head->prev = new;
	*stack = new;
	return (new);
}

/**
 * pop - remove the top element of a stack
 *
 * @stack: address of the stack
 */
void pop(stack_t **stack)
{
	stack_t *temp = *stack;

	if (temp == NULL)
		return;
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swap the top two elements of a stack
 *
 * @stack: address of the stack
 */
void swap(stack_t **stack)
{
	stack_t *first, *second, *third;

	first = *stack;
	second = first->next;
	third = second->next;

	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	*stack = second;
}

/**
 * add - add the top two elements of a stack
 *
 * @stack: address of the stack
 */
void add(stack_t **stack)
{
	stack_t *head = *stack;

	head->next->n += head->n;
	pop(stack);
}

/**
 * free_stack - free a stack_t stack
 *
 * @stack: address of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack, *temp;

	while (ptr)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
}
