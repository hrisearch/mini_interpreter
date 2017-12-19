// Hrishikesh Kulkarni  miniature interpreter

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"
#include "ast.h"

int main(int argc, char **argv)
{
	FILE *fp = assert_fopen (argv[1], "r");
	struct node *root;

	while ((root = getnode (fp)) != NULL)
	{
		int value = eval(root);
		if (value != -1)
			printf ("%d\n", value);
	}

	fclose(fp);
	return 0;
}
