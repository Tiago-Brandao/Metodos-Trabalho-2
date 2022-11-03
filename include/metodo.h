#pragma once
#include "vector"
using std::vector;

class Metodo
{
public:
  int tamanhoMatriz;
  vector<vector<double>> matriz;
  Metodo();
  Metodo(int tamanhoMatriz);

  virtual vector<double> calcularMetodo(vector<double> b) = 0;
  // void printSaida();
};