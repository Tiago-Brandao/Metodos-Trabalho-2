#include "include/lu.h"

int main()
{
  LU* teste = new LU(3);

  double* d = new double();

  teste->calcularMetodo(d);

  return 0;
}