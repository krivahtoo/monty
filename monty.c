#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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
	FILE *stream;

	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(av[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	parse_file(stream);
	fclose(stream);
	return (0);
}
