#pragma once
#include "./metodo.h"

class LU : public Metodo
{
public:
  double* l;
  double* u;

  LU();
  LU(int tamanhoMatriz);
  void inicializar();
  void calcLU();

  double* calcularMetodo(double* b);
};