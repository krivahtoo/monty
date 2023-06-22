#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *line;

void parse_file(FILE *stream);
int parse_line(stack_t **stack, unsigned int *line_no);

void opcode_pop(stack_t **stack, unsigned int line_number);
void stack_push(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);

void opcode_add(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, stack_t *node);
stack_t *pop(stack_t **stack);
void free_stack(stack_t **stack);

void opcode_swap(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
