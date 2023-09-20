#include "monty.h"

/**
 * initialize_empty_data -  a function to initialize in empty data
 * @strct: global variable parameter
 * Return: (strct)
 */
strct_t initialize_empty_data(strct_t strct)
{
	strct.file = NULL;
	strct.line = NULL;
	strct.stack = NULL;
	strct.line_number = 1;
	strct.state = 0;
	return (strct);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Pointer to arguments array
 * Return: 0 on success or 1 on error
 */
int main(int argc, char **argv)
{
	strct_t strct_var;
	char *opcode_var, *val;
	ssize_t read_var = 0;
	size_t len_var = 0;

	strct_var = initialize_empty_data(strct_var);
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	strct_var.file = fopen(argv[1], "r");
	if (!strct_var.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read_var = getline(&strct_var.line, &len_var, strct_var.file)) != -1)
	{
		opcode_var = strtok(strct_var.line, " \t");
		if (*opcode_var == '#' || *opcode_var == '\n')
		{
			strct_var.line_number++;
			continue;
		}
		if (strcmp(opcode_var, "push") == 0)
		{
			val = strtok(NULL, " ");
			strct_var = push1(val, strct_var);
			strct_var.line_number++;
			continue;
		}
		lst_opcode(&strct_var.stack, opcode_var, strct_var);
		strct_var.line_number++;
	}
	free_collect(strct_var);
	return (0);
}
