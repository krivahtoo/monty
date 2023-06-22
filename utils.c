#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - free stack memory
 *
 * @stack: pointer to the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *node = *stack;

	if (node)
	{
		free_stack(&node->next);
		free(node);
	}
}

/**
 * opcode_swap - swaps the top two elements of the stack.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *n1, *n2;

	n1 = pop(stack);
	n2 = pop(stack);

	if (n1 == NULL || n2 == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(n1);
		free(n2);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push(stack, n1);
	push(stack, n2);
}
