#include "monty.h"

/**
 * pall - prints all elements of doubly linked list or stack,
 * @stack: pointer to stack
 * @line: line number of opcode
 * Return: nothing
 */

void pall(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	for (; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}

/**
 * push - add a new node at the beginning of a doubly linked list
 * @stack: pointer to stack
 * @l_num: where opcode was found
 * @token: value converted to integer, to be aded to stack
 * Return: nothing or error
 */

void push(stack_t **stack, unsigned int l_num, char *token)
{
	stack_t *new_node = NULL;
	unsigned int i;

	if (!token)
	{
		printf("L%d: usage: push integer\n", l_num);
		error_check = 1;
		exit(EXIT_FAILURE);
	}

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] == '-') /* account for negative */
			i++;
		if (isdigit(token[i]) == 0)
		{
			printf("L%d: usage: push integer\n", l_num);
			error_check = 1;
			exit(EXIT_FAILURE);
		}
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		error_check = 1;
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(token);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pop - removes the top element of the doubly linked list
 * @stack: pointer to stack
 * @line_number: where opcode was found
 * Return: void or error
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	free(temp);

}

/**
 * pint - prints value at tope of stack, followed by a new line
 * @stack: pointer to top of soubly linked list
 * @line_number: where opcode was found in file
 * Return: void or error
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pchar - prints the char at the top of0 the stack, followed by a new line
 * @stack: pointer to stack
 * @line_number: where opcode was found
 * Return: nothing or error
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;

	if (num < 0 || num > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(num);
	putchar('\n');

}
