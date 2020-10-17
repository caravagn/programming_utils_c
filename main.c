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
  int i;

  for (i = 0; i < N; i++)
  {
    // For a double x
    // printf("x[%d] =  %f\n", i, x[i]);
    // or the analogous for the integer version
    printf("x[%d] =  %d\n", i, x[i]);

  }

  

  return(0);
}