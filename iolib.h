#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stretchy.c"

// Load arrays of int/double from file
double * read_double_array(char *, int *);
int * read_integer_array(char *, int *);

// Print to screen an array
void print_int_vector(int * , int);
void print_double_vector(double *, int);

// Dump in standardised format the output of an array
void dump_int_vector(char *, int * , int);
void dump_double_vector(char *, double *, int);

#endif