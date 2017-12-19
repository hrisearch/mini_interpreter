#ifndef AST_H_
#define AST_H_


struct node
{
	char data;
	struct node* left;
	struct node* right;
};

struct node *getnode(FILE *);
int eval(struct node *);

#endif
