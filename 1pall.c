#include "monty.h"
/**
 * pall - prints all the values on the stack, starting from the top of  stack.
 * @stack: head of the  stack
 * @line_number: param line number
 * Return: (void)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	unsigned int p = 0;
	stack_t *current_var = *stack;

	(void)line_number;

	if (current_var == NULL)
		return;


	for (p = 0; current_var; p++, current_var = current_var->next)
	{
		printf("%d\n", current_var->n);
	}

}
