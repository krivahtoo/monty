#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * stack_pint - prints the value at the top of the stack,
 * followed by a new line.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void stack_pint(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", node->n);
}
