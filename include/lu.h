#pragma once
#include "./metodo.h"
using std::cout;
using std::cin;

class LU : public Metodo
{
public:
  double** L;
  double** U;
  double** P;

  LU();
  LU(int tamanhoMatriz, bool pivoParcial);
  void inicializar();
  void calcLU();

  double* calcularMetodo(double* b);
  double* calcY(double* b);
  double* calcX(double *y);
  double calcRazao(int i, int j);
  void trocarLinhas(int linha1, int linha2);
  void mudarL(int linha1, int linha2);
};