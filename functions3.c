#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: where opcode was found
 * Return: nothing or error
 */

void swap(stack_t **stack, unsigned int line_number)
{

	unsigned int num_nodes;
	int temp_head, temp_new_head;
	stack_t *current;

	current = *stack;
	num_nodes = 0;
	if (current == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		current = current->next;
		num_nodes += 1;
	}

	if (num_nodes < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_head = (*stack)->n;
	temp_new_head = (*stack)->next->n;
	(*stack)->n = temp_new_head;
	(*stack)->next->n = temp_head;
}

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: pointer to stack
 * @line_number: unused
 * Return: nothing or error
 */

void sub(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	unsigned int num_nodes;
	int top_num, second_num, total;
	stack_t *current;

	current = *stack;
	num_nodes = 0;
	if (current == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		current = current->next;
		num_nodes += 1;
	}

	if (num_nodes < 2)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_num = (*stack)->n;
	second_num = (*stack)->next->n;
	total = second_num - top_num;

	pop(stack, line_number);

	(*stack)->n = total;
}

/**
 * free_dlistint - frees linked list
 * @head: pointer to head of linked list
 * Return: void or error
 */
void free_dlistint(stack_t **head)
{
	stack_t *tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

/**
 * free_all - frees linked list
 * @stack: linked list
 * @line: line from getline to be free
 * @fp: file to pointer
 * Return: void or error
 */

void free_all(stack_t *stack, char *line, FILE *fp)
{
	if (stack != NULL)
		free_dlistint(&stack);
	free(line);
	fclose(fp);
}
