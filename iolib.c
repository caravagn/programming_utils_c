#include "iolib.h"

// Load a vector of double values stored, line by line, in file "file". Use "N" to store the number of values in the returned vector
double * read_double_array(char * file, int * N)
{
  // Prepare input file reference
  printf(" =-= Loading input from file: \"%s\".\n", file);

  FILE *myFile;    
  myFile = fopen(file, "r");
   
  assert(myFile != NULL);

  // Load, line-by-line all file's lines (max 100 char per line)
  double *v = 0;
  *N = 0;
  char currentline[100];
  
  while (fgets(currentline, sizeof(currentline), myFile) != NULL) 
  {
    *N = *N + 1;

    // debugging line 
    // fprintf(stderr, "got line: %s\n", currentline);

    // Store `currentline` - dynamic memory allocation
    sb_push(v, atof(currentline));
  }

  // Report to stdio what we found
  printf(" =-= Found n = %d values.\n", *N);

  // Close file
  fclose(myFile);

  // Make pointer available
  return(v);
}

// Load a vector of int values stored, line by line, in file "file". Use "N" to store the number of values in the returned vector
int * read_integer_array(char * file, int * N)
{
  double * x = read_double_array(file, N);
  
  // Convert types
  int * int_x = malloc(*N * sizeof(int));

  int i;

  for (i = 0; i < *N; i++) int_x[i] = (int) *(x+i);
  
  // Make pointer available
  return(int_x);
}

void print_int_vector(int * x, int n)
{
   // Visualisation
  int i;

  for (i = 0; i < n; i++)
  {
    printf("x[%d] =  %d\n", i, x[i]);
  }
}

void print_double_vector(double * x, int n)
{
   // Visualisation
  int i;

  for (i = 0; i < n; i++)
  {
    printf("x[%d] =  %f\n", i, x[i]);
  }
}