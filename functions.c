#include "monty.h"
/**
 * add - adds two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: not used
 * Return: nothing or error
 */
void add(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	unsigned int num_nodes;
	int top_num, second_num, total;
	stack_t *current;

	current = *stack;
	num_nodes = 0;
	if (current == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		current = current->next;
		num_nodes += 1;
	}

	if (num_nodes < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_num = (*stack)->n;
	second_num = (*stack)->next->n;
	total = top_num + second_num;

	pop(stack, line_number);

	(*stack)->n = total;
}

/**
 * _div - divides the second element by the top element of the stack
 * @stack: pointer  stack
 * @line_number: where opcode was found
 * Return: nothing or error
 */

void _div(stack_t **stack, unsigned int line_number)
{
	unsigned int num_nodes;
	int top_num, second_num, total;
	stack_t *current;

	current = *stack;
	num_nodes = 0;
	if (current == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		error_check = 1;
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		current = current->next;
		num_nodes += 1;
	}

	if (num_nodes < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		error_check = 1;
		exit(EXIT_FAILURE);
	}

	top_num = (*stack)->n;
	second_num = (*stack)->next->n;

	if (top_num == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_check = 1;
		exit(EXIT_FAILURE);
	}

	total = second_num / top_num;

	pop(stack, line_number);

	(*stack)->n = total;
}

/**
 * mod -  computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * @stack: pointer to top of stack
 * @line_number: where opcode was found
 * Return: nothing or error
 */

void mod(stack_t **stack, unsigned int line_number)
{
	unsigned int num_nodes;
	int top_num, second_num, total;
	stack_t *current;

	current = *stack;
	num_nodes = 0;
	if (current == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		current = current->next;
		num_nodes += 1;
	}

	if (num_nodes < 2)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_num = (*stack)->n;
	second_num = (*stack)->next->n;

	if (top_num == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = second_num % top_num;

	pop(stack, line_number);

	(*stack)->n = total;
}

/**
 * nop - does absolutely NOTHING LMAOO
 * @stack: pointer to stack
 * @line_number: N/A void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}

/**
 * mul - multiplies top element of the stack
 * with the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number where opcode was found
 * Return: nothing or error
 */

void mul(stack_t **stack, unsigned int line_number)
{
	unsigned int num_nodes;
	int top_num, second_num, total;
	stack_t *current;

	current = *stack;
	num_nodes = 0;
	if (current == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		current = current->next;
		num_nodes += 1;
	}

	if (num_nodes < 2)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_num = (*stack)->n;
	second_num = (*stack)->next->n;

	total = second_num * top_num;

	pop(stack, line_number);

	(*stack)->n = total;
}
