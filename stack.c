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
