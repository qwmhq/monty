#include "monty.h"

/**
 * get_opcode_func - get the appropriate function for an opcode
 *
 * @opcode: opcode
 *
 * Return: opcode function
 */
void (*get_opcode_func(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{NULL, NULL}
	};

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (instructions[i].f);
}
