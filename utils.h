#ifndef UTILS_H_
#define UTILS_H_

#include <stddef.h>
#include <stdio.h>

void *assert_malloc (size_t);
FILE *assert_fopen (char *, char *);
int is_oper(int);

#endif
