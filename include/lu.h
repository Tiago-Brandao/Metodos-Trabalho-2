#pragma once
#include "./metodo.h"

class LU : public Metodo
{
public:
  double** L;
  double** U;
  double** P;

  // Tratar os casos de divisão por zero!
  bool valido;

  LU();
  LU(int tamanhoMatriz, bool pivoParcial);

  void inicializar();
  void calcLU();

  double* calcularMetodo(double* b);
  double* calcY(double* b);
  double* calcX(double *y);
  double calcRazao(int i, int j, bool pivo_Parcial_ja_foi_feito);

  void trocarLinhas(int linha1, int linha2);
};