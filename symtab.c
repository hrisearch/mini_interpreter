#include <stdio.h>
#include <stdlib.h>
#include "symtab.h"

static int symtab['z' - 'a' + 1];

void store(char var, int value)
{
	symtab[var - 'a'] = value;	
}

int getval(char var)
{
	int val = symtab[var - 'a'];
	if (val == -1)
	{
		fprintf (stderr, "Unknown variable %c\n", var);
		exit (EXIT_FAILURE);
	}
	return val;
}
