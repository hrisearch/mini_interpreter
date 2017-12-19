// Utility functions

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "assert.h"

void *
assert_malloc(size_t nunits)
{
	void *p = malloc (nunits);
	assert (p != NULL);
	return p;	
}

FILE *
assert_fopen (char *fname, char *mode)
{
	FILE *fp = fopen (fname, mode);
	assert (fp);
	return fp;
}

int
is_oper(int c)
{
	switch (c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
}
