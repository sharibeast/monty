#include "monty.h"

/**
 * free_stck - function to free the stack
 * @head: ptr param for head
 * Return: void
 */

void free_stck(stack_t *head)
{
	stack_t *temporary_var;
	stack_t *current_var = head;

	while (current_var)
	{
		temporary_var = current_var->next;
		free(current_var);
		current_var = temporary_var;
	}
}


