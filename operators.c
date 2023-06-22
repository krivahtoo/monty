#include "monty.h"
#include <stdlib.h>

/**
 * opcode_add - adds the top two elements of the stack.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	stack_t *n1, *n2, *new = NULL;

	n1 = pop(stack);
	n2 = pop(stack);

	if (n1 == NULL || n2 == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(n1);
		free(n2);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(n1);
		free(n2);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = n1->n + n2->n;
	new->next = NULL;
	new->prev = NULL;
	push(stack, new);
	free(n1);
	free(n2);
}
