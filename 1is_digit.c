#include "monty.h"


/**
 * _isdigit - is digit description
 * @str: string param
 * Return: true / false
 */

int _isdigit(char *str)
{
	int p = 0;

	while (str[p])
	{
		if (str[p] == '-')
		{
			p++;
			continue;
		}
		else if (!isdigit(str[p]))
			return (0);

		p++;
	}
	return (1);
}
