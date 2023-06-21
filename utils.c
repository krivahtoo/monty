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
