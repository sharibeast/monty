#include "monty.h"

/**
 * push - push node to stack (description)
 * @value: node value
 * @strct: parameter
 * Return: rturn
 */
strct_t push(char *value, strct_t strct)
{
	register int x;
	char *ptr = NULL;
	stack_t *new_var, *current_var = strct.stack;

	ptr = strchr(value, '\n');
	if (ptr)
		*ptr = 0;
	if (!strlen(value) || !_isdigit(value))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", strct.line_number);
		fclose(strct.file);
		free(strct.line);
		free_stck(strct.stack);
		exit(EXIT_FAILURE);
	}
	x = atoi(value);
	new_var = malloc(sizeof(stack_t));
	if (!new_var)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(strct.file);
		free(strct.line);
		free_stck(strct.stack);
		exit(EXIT_FAILURE);
	}
	new_var->n = x;
	new_var->next = NULL;
	if (!current_var)
	{
		new_var->prev = NULL;
		strct.stack = new_var;
		return (strct);
	}
	while (current_var->next)
	{
		current_var = current_var->next;
	}
	current_var->next = new_var;
	new_var->prev = current_var;
	return (strct);
}

