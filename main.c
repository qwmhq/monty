#include "monty.h"

int stack_mode = 1;

/**
 * main - monty main
 *
 * @argc: argument count
 * @argv: array of argument values
 *
 * Return: always 0.
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 1;
	size_t len = 0;
	ssize_t nread;
	char *line = NULL, *opcode;
	FILE *fp;
	stack_t *stack = NULL;
	void (*opcode_func)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, fp)) != -1)
	{
		opcode = strtok(line, DELIM);
		if (opcode == NULL || *opcode == '#')
			continue;
		opcode_func = get_opcode_func(opcode);
		if (opcode_func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		opcode_func(&stack, line_number);
		line_number++;
	}
	free_stack(&stack);
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
