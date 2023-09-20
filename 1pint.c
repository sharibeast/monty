#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: head stack params
 * @line_number: line number param
 * Return: (void)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current_var = *stack;

	if (!current_var)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current_var->n);
}
