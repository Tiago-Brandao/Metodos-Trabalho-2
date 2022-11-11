#include "include/lu.h"

int main()
{
  LU* teste = new LU(3, true);

  double* d = (double *) malloc(sizeof(double) * 3);
  /*
  d[0] = 11;
  d[1] = -15;
  d[2] = 29;
  */

  /*
  d[0] = 9;
  d[1] = 3;
  d[2] = -2;
  */

  d[0] = 1;
  d[1] = 2;
  d[2] = 3;

  teste->calcularMetodo(d);

  return 0;
}