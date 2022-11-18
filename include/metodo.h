#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
using std::cout;

class Metodo {
public:
  int tamanhoMatriz;
  double** M;
  bool pivoParcial;

  Metodo();
  Metodo(double** matriz, int tamanhoMatriz, bool pivoParcial);

  virtual double* calcularMetodo(double* b) = 0;

  // Set
  void setM(double** matriz);
};

double** inicializarMatriz(int tamanhoMatriz);
double** prodMM(double** A, double** B, int tamanhoMatriz);
double* prodMV(double** M, double *V, int n);
