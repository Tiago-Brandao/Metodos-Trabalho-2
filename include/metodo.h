#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
using std::cout;

class Metodo
{
public:
  int tamanhoMatriz;
  // double* matriz;
  double** M;
  Metodo();
  Metodo(int tamanhoMatriz);

  virtual double* calcularMetodo(double* b) = 0;
};

double** inicializarMatriz(int tamanhoMatriz);