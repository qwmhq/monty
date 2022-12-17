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
		{"pint", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{"sub", NULL},
		{"div", NULL},
		{"mul", NULL},
		{"mod", NULL},
		{"pchar", NULL},
		{"pstr", NULL},
		{"rotl", NULL},
		{"rotr", NULL},
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
