#include "monty.h"

/**
 * sub - sub description
 * @stack: head stack param
 * @line_number: line number params
 * Return: (void)
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *next_var;
	stack_t *current_var = *stack;

	if (!current_var || !current_var->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next_var = current_var->next;
	next_var->n -= current_var->n;
	pop(stack, line_number);
}
