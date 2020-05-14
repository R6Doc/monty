#include "monty.h"
/**
 * get_opcode_func - looks for opcode and executes it
 * @opcode: opcode that calls the function
 * @stack: pointer to stack
 * @line_num: line_number opcode is found
 * Return: exit in successss
 */
int get_opcode_func(char *opcode, stack_t **stack, unsigned int line_num)
{
	instruction_t op_codes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};
	unsigned int i;

	i = 0;
	while (op_codes[i].opcode != NULL)
	{
		if (strcmp(opcode, op_codes[i].opcode) == 0)
		{
			(op_codes[i].f)(stack, line_num);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_num, opcode);
	error_check = 1;
	exit(EXIT_FAILURE);
}
