#include "monty.h"

/**
 * add - add element in stack
 * @stack: head param
 * @line_number: line params
 * Return: (void)
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current_var = *stack;
	stack_t *next_var;

	if (!current_var || !current_var->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next_var = current_var->next;
	next_var->n += current_var->n;
	pop(stack, line_number);
}
