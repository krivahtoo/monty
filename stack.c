#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * opcode_push - push a value to stack
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	char *tmp = NULL, *token = NULL;
	stack_t *new = NULL;
	int i = 0;

	tmp = strdup(ctx.line);
	token = strtok(tmp, " ");
	if (token == NULL)
	{
bail:
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_ctx();
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " ");
	i = atoi(token);
	if (token == NULL || (i == 0 && *token != '0'))
		goto bail;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_ctx();
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = i;
	new->next = NULL;
	new->prev = NULL;
	push(stack, new, ctx.fmt);
	free(tmp);
}

/**
 * push - push a value to stack
 *
 * @stack: pointer to the stack
 * @node: pointer to node
 * @back: if to pust to back
 */
void push(stack_t **stack, stack_t *node, int back)
{
	stack_t *tmp = *stack, *old = NULL;

	switch (back)
	{
		case 0:
			node->next = tmp;
			*stack = node;
			if (tmp)
				tmp->prev = node;
			break;
		case 1:
			while (tmp != NULL)
			{
				old = tmp;
				tmp = tmp->next;
			}
			node->prev = old;
			if (old == NULL)
				*stack = node;
			else
				old->next = node;
			break;
		default:
			break;
	}
}

/**
 * opcode_pop - pop a value from stack
 *
 * @stack: pointer to the stack
 * @line_number: number of the line
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = pop(stack, 0);

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_ctx();
		exit(EXIT_FAILURE);
	}
	free(node);
}

/**
 * pop - pop a value from stack
 *
 * @stack: pointer to the stack
 * @back: if to pop from back
 *
 * Return: the popped value
 */
stack_t *pop(stack_t **stack, int back)
{
	stack_t *node = *stack;

	switch (back)
	{
		case 0:
			if (node == NULL)
				return (NULL);
			*stack = node->next;
			if (node->next)
				node->next->prev = NULL;
			node->next = NULL;
			break;
		case 1:
			while (node && node->next)
			{
				node = node->next;
			}
			if (node != NULL)
			{
				if (node->prev)
					node->prev->next = NULL;
				else
					*stack = NULL;
				node->prev = NULL;
			}
			break;
		default:
			break;
	}
	return (node);
}
