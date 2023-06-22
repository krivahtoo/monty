#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *line = NULL;

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
	char *tmp = NULL;
	char *token = NULL;
	instruction_t inst[] = {
		{ "push", stack_push },
		{ "pall", stack_pall },
		{ "pop", opcode_pop },
		{ NULL, NULL },
	};

	(*line_no)++;
	tmp = strtok(line, "\n");
	tmp = strdup(tmp);
	token = strtok(tmp, " ");
	if (token == NULL)
		goto end;
	for (i = 0; inst[i].opcode; i++)
	{
		if (strcmp(token, inst[i].opcode) == 0)
		{
			inst[i].f(stack, *line_no);
			goto end;
		}
	}
	if (strcmp(token, "") != 0)
	{
		free(tmp);
		return (1);
	}
end:
	free(tmp);
	return (0);
}

/**
 * parse_file - reads a file and executes the instructions in it
 *
 * @stream: file to read from
 */
void parse_file(FILE *stream)
{
	size_t size = 0;
	unsigned int line_no = 0;
	stack_t *stack = NULL;
	char *token;

	while (1)
	{
		free(line);
		line = NULL;
		if (getline(&line, &size, stream) == EOF)
			break;
		if (strcmp(line, "\n") == 0)
			continue;
		if (parse_line(&stack, &line_no) != 0)
		{
			token = strtok(line, " ");
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, token);
			fclose(stream);
			free(line);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free_stack(&stack);
}
