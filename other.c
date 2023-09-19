#include "monty.h"

/**
 * file_reader - read monty file
 * @filename: str name of monty opcode file
 * @stack: double ptr to top of DS stack
 *
 */

glob_vars globv;

int file_reader(char *filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
	char *op;


	if (!filename)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	atexit(free_all);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		op = strtok(line, "\n\t\r ");
		line_number++;
		if (op)
			get_po(stack, op, line_number);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}



/**
 * stack_init - function that initializes all the things.
 * @head: double pointer to top of stack.
 *
 * Return: No return.
 **/
void stack_init(stack_t **head)
{
	*head = NULL;
	globv.top = head;
}

/**
 * free_all - function that frees all malloc'ed memory.
 *
 * Return: No return.
 **/
void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(globv.top);
	/* printf("glob.top->%p\n",  (void*)glob.top); */
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
