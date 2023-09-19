#include "monty.h"

/**
 * _pall - print all values from the top of the stack
 *
 * @stack: - pointer to head
 * @line_number: - line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *elem = *stack;

	(void)(line_number);
	while (elem != NULL)
	{
		printf("%d\n", elem->n);
		elem = elem->next;
	}
}

/**
 * _push - push element to stack
 *
 * @stack: - pointer to head
 * @line_number: - line number
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *opcode;
	int num;

	if (!element)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}



