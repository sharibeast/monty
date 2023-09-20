#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: param for head stack
 * @line_number: param for line number
 * Return: (void)
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current_var = *stack;
	stack_t *next_var;

	if (!current_var)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	next_var = current_var->next;
	free(current_var);
	*stack = next_var;
	current_var = *stack;
	if (current_var)
		current_var->prev = NULL;
}
