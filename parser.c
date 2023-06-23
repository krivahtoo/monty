#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * parse_line - parses a line of monty code
 *
 * @stack: pointer to the stack
 * @line_no: pointer to the line number
 *
 * Return: 0 on success, 1 on error
 */
int parse_line(stack_t **stack, unsigned int *line_no)
{
	int i = 0;
	char *token = NULL;
	instruction_t inst[] = INSTRUCTIONS();

	token = strtok(ctx.line, "\n");
	while (*token == ' ')
		token++;
	if (token == NULL || *token == '#')
		goto end;
	for (i = 0; inst[i].opcode; i++)
	{
		if (strncmp(token, inst[i].opcode, strlen(inst[i].opcode)) == 0)
		{
			inst[i].f(stack, *line_no);
			goto end;
		}
	}
	if (strcmp(token, "") != 0)
		return (1);
end:
	return (0);
}

/**
 * parse_file - reads a file and executes the instructions in it
 */
void parse_file(void)
{
	size_t size = 0;
	unsigned int line_no = 0;
	stack_t *stack = NULL;
	char *token;

	while (1)
	{
		free(ctx.line);
		ctx.line = NULL;
		if (getline(&ctx.line, &size, ctx.stream) == EOF)
			break;
		line_no++;
		if (strcmp(ctx.line, "\n") == 0)
			continue;
		if (parse_line(&stack, &line_no) != 0)
		{
			token = strtok(ctx.line, " ");
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, token);
			free_ctx();
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&stack);
}
