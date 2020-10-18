#include "iolib.h"

// Load a vector of double values stored, line by line, in file "file". Use "N" to store the number of values in the returned vector
double * read_double_array(char * file, int * N)
{
  // add full path to folder input/...
  char fullpath[100] = "input/";
  strcat(fullpath, file);

  // Prepare input file reference
  printf("=-= Loading input from file: \"%s\".\n", fullpath);

  FILE *myFile;    
  myFile = fopen(fullpath, "r");
   
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
  printf("=-= Found n = %d values.\n", *N);

  // Close file
  fclose(myFile);

  // Make pointer available
  return(v);
}

// Load a vector of int values stored, line by line, in file "file". Use "N" to store the number of values in the returned vector.
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

// Print an array of integers to screen - shows only the first 5 entries if there are more than 5
void print_int_vector(int * x, int n)
{
   // Visualisation
  int i;

   // Behave like "head"
  int cut = 1;

  if(n > 5) {
    cut = 0;
    printf("=-= More than 5 elements, showing first 5\n");
    n = 5;
  }

  for (i = 0; i < n; i++)
  {
    printf("=-= x[%d] =  %d\n", i, x[i]);
  }

  if(cut == 0) printf("=-= ... \n");

}

// Print an array of double to screen - shows only the first 5 entries if there are more than 5
void print_double_vector(double * x, int n)
{
   // Visualisation
  int i;

  // Behave like "head"
  int cut = 1;

  if(n > 5) {
    cut = 0;
    printf("=-= More than 5 elements, showing first 5\n");
    n = 5;
  }

  for (i = 0; i < n; i++)
  {
    printf("=-= x[%d] =  %f\n", i, x[i]);
  }

  if(cut == 0) printf("=-= ... \n");
}

// Dump a vector of array to a file
void dump_int_vector(char * file, int * x, int n)
{
  // add full path to folder output/...
  char fullpath[100] = "output/";
  strcat(fullpath, file);

   // Prepare input file reference
  printf("=-= Writing output to file: \"%s\".\n", fullpath);

  FILE *myFile;    
  myFile = fopen(fullpath, "w");

  int i;
  for(i = 0; i < n; i++)
    fprintf(myFile, "%d\n", x[i]);  

  fclose(myFile);

  // Visualisation
  print_int_vector(x, n);
}


void dump_double_vector(char * file, double * x, int n)
{
   // add full path to folder output/...
  char fullpath[100] = "output/";
  strcat(fullpath, file);

   // Prepare input file reference
  printf("=-= Writing output to file: \"%s\".\n", fullpath);

  FILE *myFile;    
  myFile = fopen(fullpath, "w");

  //fwrite(x, sizeof(x), 1, myFile); /* Write to File */
  //
  int i;
  for(i = 0; i < n; i++)
    fprintf(myFile, "%f\n", x[i]);  

  fclose(myFile);

  // Visualisation
  print_double_vector(x, n);  
}