
#include "monty.h"

/**
 * lst_opcode - List all the opcode
 * instruction_table_var: instructions
 * @stack: param
 * @strct: param
 * @opcode: opcode
 */
void lst_opcode(stack_t **stack, char *opcode, strct_t strct)
{
	instruction_t instruction_table_var[] = {
	    {"add", add},
	    {"sub", sub},
	    {"pint", pint},
	    {"pop", pop},
	    {"swap_fn", swap_fn},
	    {"nope_fn", nope_fn},
	    {"pall", pall},
	    {NULL, NULL}};
	register int y;
	char *opcode_var;

	opcode_var = strtok(opcode, "\n");
	for (y = 0; instruction_table_var[y].opcode; y++)
		if (strcmp(opcode_var, instruction_table_var[y].opcode) == 0)
		{
			instruction_table_var[y].f(stack, strct.line_number);
			return;
		}

	dprintf(STDERR_FILENO, "L%d: ", strct.line_number);
	dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
	fclose(strct.file);
	free(strct.line);
	free_stck(strct.stack);
	exit(EXIT_FAILURE);
}
