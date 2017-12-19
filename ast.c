#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"
#include "symtab.h"
#include "ast.h"

struct node *
getnode (FILE *fp)
{
	//printf("chalu\n");
	int c;
	struct node *root;

	do
	{
		c = getc (fp);
		if (c == EOF)
			return NULL;
		//scanf("%c", &c);
	}while(c=='(' || c==')' || c=='\n' );

	root = assert_malloc (sizeof (*root));
	root->data = (isdigit (c)) ? c - '0' : c;

	if (!is_oper (c) && c != '=')
		return root;

	//printf("startl %c \n", c);
	root->left = getnode (fp);
	//printf("endl\n");

	//printf("startr %c \n", c);
	root->right = getnode (fp);
	//printf("endr\n");
	return root;
}

static int val(char op, char l, char r)
{
	char c ='0';
	switch(op)
	{
		case '+':
			return l + r;
		case '-':
			return l - r;
		case '*':
			return l * r;
		case '/':
			return l / r;
		default:
			assert (0);
	}
	//printf("err\n");
}

int
eval(struct node* root)
{
	//printf("%c \n", root->data);
	int left_op, right_op;

	if (is_oper (root->data))
	{
		left_op = eval(root->left);
		right_op = eval(root->right);
		return val(root->data, left_op, right_op);
	}

	else if (root->data == '=')
	{
		char id = root->left->data;
		right_op = eval(root->right);
		store (id, right_op);
		return -1;
	}

	else if (isalpha (root->data))
		return getval(root->data);

	else
		return root->data;
}
