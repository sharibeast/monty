#include "monty.h"

/**
 * free_collect - function for free_collect (instrct)
 * @strct: strct_t strct
 * Return: strct
 */
strct_t free_collect(strct_t strct)
{
	fclose(strct.file);
	if (strct.line)
	{
		free(strct.line);
		strct.line = NULL;
	}
	if (strct.stack)
	{
		free_stck(strct.stack);
		strct.stack =  NULL;
	}
	return (strct);
}
