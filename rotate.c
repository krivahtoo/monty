#include "monty.h"

/**
 * opcode_rotl - rotates the stack to the top.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node = pop(stack, 0);

	(void)line_number;
	if (node)
		push(stack, node, 1);
}

/**
 * opcode_rotr - rotates the stack to the bottom.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = pop(stack, 1);

	(void)line_number;
	if (node)
		push(stack, node, 0);
}
