#include "iolib.c"


int main(int argc, char *argv[])
{
  // input file: argv[1]
  // array size: to be declared
  int N;
  
  // How to get a vector of doubles
  // double * x = read_double_array(argv[1], &N);
  // or the analogous with integers
  int * x = read_integer_array(argv[1], &N);

  // Visualisation
  print_int_vector(x, N);

  // Some simple modification of the data
  int i;
  for(i = 0; i < N; i++) x[i] = i;

  // Dump to file in output folder
  dump_int_vector(argv[1], x, N);


  return(0);
}