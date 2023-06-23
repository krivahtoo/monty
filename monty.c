#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

context_t ctx = { NULL, LIFO, NULL };

/**
 * free_ctx - free program context
 */
void free_ctx(void)
{
	free(ctx.line);
	fclose(ctx.stream);
}

/**
 * main - entry point
 *
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: Always 0
 */
int main(int ac, char *av[])
{
	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ctx.stream = fopen(av[1], "r");
	if (ctx.stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	parse_file(ctx.stream);
	free_ctx();
	return (0);
}
