#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * opcode_pall - prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * opcode_pint - prints the value at the top of the stack,
 * followed by a new line.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_ctx();
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", node->n);
}

/**
 * opcode_pchar - prints the char at the top of the stack,
 * followed by a new line.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int n;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_ctx();
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	n = node->n;
	if (n > 127 || n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_ctx();
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char) n);
}

/**
 * opcode_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int n;

	(void)line_number;
	while (node != NULL)
	{
		n = node->n;
		if (n <= 0 || n > 127)
			break;
		printf("%c", (char) n);
		node = node->next;
	}
	printf("\n");
}
