#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

#define INSTRUCTIONS() {			\
		{ "push", opcode_push },	\
		{ "pall", opcode_pall },	\
		{ "pint", opcode_pint },	\
		{ "pop", opcode_pop },		\
		{ "swap", opcode_swap },	\
		{ "add", opcode_add },		\
		{ "nop", opcode_nop },		\
		{ "sub", opcode_sub },		\
		{ "div", opcode_div },		\
		{ "mul", opcode_mul },		\
		{ "mod", opcode_mod },		\
		{ "pchar", opcode_pchar },	\
		{ "pstr", opcode_pstr },	\
		{ "stack", opcode_stack },	\
		{ "queue", opcode_queue },	\
		{ "rotl", opcode_rotl },	\
		{ "rotr", opcode_rotr },	\
		{ NULL, NULL },				\
	}

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

/**
 * enum format_e - stack format LIFO/FIFO
 * @LIFO: Last in first out
 * @FIFO: First in first out
 */
typedef enum format_e
{
	LIFO = 0,
	FIFO
} format_t;

/**
 * struct context_s - current program context
 * @line: line buffer
 * @fmt: stack format
 * @stream: file strem
 */
typedef struct context_s
{
	char *line;
	format_t fmt;
	FILE *stream;
} context_t;

extern context_t ctx;

void free_ctx(void);

void parse_file(void);
int parse_line(stack_t **stack, unsigned int *line_no);

void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_push(stack_t **stack, unsigned int line_number);

void opcode_pall(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pchar(stack_t **stack, unsigned int line_number);
void opcode_pstr(stack_t **stack, unsigned int line_number);

void opcode_add(stack_t **stack, unsigned int line_number);
void opcode_sub(stack_t **stack, unsigned int line_number);
void opcode_div(stack_t **stack, unsigned int line_number);
void opcode_mul(stack_t **stack, unsigned int line_number);
void opcode_mod(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, stack_t *node, int back);
stack_t *pop(stack_t **stack, int back);
void free_stack(stack_t **stack);

void opcode_swap(stack_t **stack, unsigned int line_number);
void opcode_nop(stack_t **stack, unsigned int line_number);
void opcode_stack(stack_t **stack, unsigned int line_number);
void opcode_queue(stack_t **stack, unsigned int line_number);

void opcode_rotl(stack_t **stack, unsigned int line_number);
void opcode_rotr(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
