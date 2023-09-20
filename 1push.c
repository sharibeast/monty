#include "monty.h"
/**
 * push1 - add new node in a stack
 * @value: vlue of node
 * @strct: param
 * Return: return
 */
strct_t push1(char *value, strct_t strct)
{
	char *ptr_var = NULL;
	stack_t *nw_var;

	register int x;

	ptr_var = strchr(value, '\n');
	if (ptr_var)
		*ptr_var = 0;
	if (!strlen(value) || !_isdigit(value))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", strct.line_number);
		fclose(strct.file);
		free(strct.line);
		free_stck(strct.stack);
		exit(EXIT_FAILURE);
	}
	x = atoi(value);
	nw_var = malloc(sizeof(stack_t));
	if (!nw_var)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(strct.file);
		free(strct.line);
		free_stck(strct.stack);
		exit(EXIT_FAILURE);
	}
	nw_var->n = x;
	nw_var->next = strct.stack;
	nw_var->prev = NULL;
	if (nw_var->next)
		nw_var->next->prev = nw_var;
	strct.stack = nw_var;
	return (strct);
}
