#ifndef OPERATORS_H
#define OPERATORS_H

#define BAIL() do {			\
	free((n1));				\
	free((n2));				\
	free_ctx();				\
	free_stack((stack));	\
	exit(EXIT_FAILURE);		\
} while ((1))


#endif  /* OPERATORS_H */
