#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <assert.h>
#include "stretchy.c"

double * read_double_array(char *, int *);
int * read_integer_array(char *, int *);

void print_int_vector(double * , int);
void print_double_vector(double *, int);

#endif