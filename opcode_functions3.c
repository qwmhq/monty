#include "monty.h"

/**
 * rotr_op - rotr opcode function
 *
 * @stack: the stack
 * @line_number: the current line number
 */
void rotr_op(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	rotr(stack);
}
