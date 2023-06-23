#include "monty.h"
#include "operators.h"
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

	n1 = pop(stack, 0);
	n2 = pop(stack, 0);

	if (n1 == NULL || n2 == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		BAIL();
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		BAIL();
	}
	new->n = n1->n + n2->n;
	new->next = NULL;
	new->prev = NULL;
	push(stack, new, 0);
	free(n1);
	free(n2);
}

/**
 * opcode_sub - subtracts the top element of the stack from the
 * second top element of the stack.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *n1, *n2, *new = NULL;

	n1 = pop(stack, 0);
	n2 = pop(stack, 0);

	if (n1 == NULL || n2 == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		BAIL();
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		BAIL();
	}
	new->n = n2->n - n1->n;
	new->next = NULL;
	new->prev = NULL;
	push(stack, new, 0);
	free(n1);
	free(n2);
}

/**
 * opcode_div - divides the second top element of the stack by the top
 * element of the stack.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	stack_t *n1, *n2, *new = NULL;

	n1 = pop(stack, 0);
	n2 = pop(stack, 0);

	if (n1 == NULL || n2 == NULL || n1->n == 0)
	{
		if (n1 && n1->n == 0)
			fprintf(stderr, "L%d: division by zero\n", line_number);
		else
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		BAIL();
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		BAIL();
	}
	new->n = n2->n / n1->n;
	new->next = NULL;
	new->prev = NULL;
	push(stack, new, 0);
	free(n1);
	free(n2);
}

/**
 * opcode_mul - multiplies the second top element of the stack with the
 * top element of the stack.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *n1, *n2, *new = NULL;

	n1 = pop(stack, 0);
	n2 = pop(stack, 0);

	if (n1 == NULL || n2 == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		BAIL();
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		BAIL();
	}
	new->n = n2->n * n1->n;
	new->next = NULL;
	new->prev = NULL;
	push(stack, new, 0);
	free(n1);
	free(n2);
}

/**
 * opcode_mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *n1, *n2, *new = NULL;

	n1 = pop(stack, 0);
	n2 = pop(stack, 0);

	if (n1 == NULL || n2 == NULL || n1->n == 0)
	{
		if (n1 && n1->n == 0)
			fprintf(stderr, "L%d: division by zero\n", line_number);
		else
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		BAIL();
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		BAIL();
	}
	new->n = n2->n % n1->n;
	new->next = NULL;
	new->prev = NULL;
	push(stack, new, 0);
	free(n1);
	free(n2);
}
