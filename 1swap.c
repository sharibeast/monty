#include "monty.h"

/**
 * swap_fn - swap_fn two elements
 * @stack: head params
 * @line_number: line number params
 * Return: (void)
 */
void swap_fn(stack_t **stack, unsigned int line_number)
{
	register int temporary_var;
	stack_t *current_var = *stack;
	stack_t *next_var;

	if (!current_var || !current_var->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next_var = current_var->next;
	temporary_var = current_var->n;
	current_var->n = next_var->n;
	next_var->n = temporary_var;
}
