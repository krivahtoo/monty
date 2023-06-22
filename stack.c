#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * stack_push - push a value to stack
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void stack_push(stack_t **stack, unsigned int line_number)
{
	char *tmp = NULL, *token = NULL;
	stack_t *new = NULL, *node = *stack;
	int i = 0;

	tmp = strdup(line);
	token = strtok(tmp, " ");
	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	i = atoi(strtok(NULL, " "));
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = i;
	new->next = node;
	new->prev = NULL;
	*stack = new;
	if (node != NULL)
		node->prev = new;
	free(tmp);
}

/**
 * opcode_pop - pop a value from stack
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = stack_pop(stack);

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	free(node);
}

/**
 * stack_pall - prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void stack_pall(stack_t **stack, unsigned int line_number)
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
 * stack_pop - pop a value from stack
 *
 * @stack: pointer to the stack
 *
 * Return: the popped value
 */
stack_t *stack_pop(stack_t **stack)
{
	stack_t *node = *stack;

	if (node == NULL)
		return (NULL);
	*stack = node->next;
	if (node->next)
		node->next->prev = NULL;
	node->next = NULL;
	return (node);
}
