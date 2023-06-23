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
 * opcode_nop - does nothing
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do Nothing */
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

	n1 = pop(stack, 0);
	n2 = pop(stack, 0);

	if (n1 == NULL || n2 == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(n1);
		free(n2);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push(stack, n1, 0);
	push(stack, n2, 0);
}

/**
 * opcode_stack - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	ctx.fmt = LIFO;
}

/**
 * opcode_queue - sets the format of the data to a queue (FIFO).
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	ctx.fmt = FIFO;
}
