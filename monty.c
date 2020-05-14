#include "monty.h"
int error_check = 0;
/**
 * main - main file with functions related to free and eexcute
 * @argc: argument count
 * @argv: double pointer to arguments given
 * Return: 0 on success, exit(1)
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line, *token;
	size_t len;
	unsigned int line_num;
	stack_t *stack;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_num = 0;
	stack = NULL;
	line = token = NULL;
	len = 0;
	while (getline(&line, &len, fp) != -1 && error_check == 0)
	{
		line_num++; /* opcode found */
		token = strtok(line, "\n\t\r "); /* check for empty line */
		if (token == NULL || strncmp(token, "#", 1) == 0)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			push(&stack, line_num, token);
		}
		else
			get_opcode_func(token, &stack, line_num);
	}
	free_all(stack, line, fp);
	if (error_check != 0)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
