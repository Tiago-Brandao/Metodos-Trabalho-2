#include "../include/metodo.h"

Metodo::Metodo(){}

Metodo::Metodo(int tamanhoMatriz)
{
  this->tamanhoMatriz = tamanhoMatriz;
  this->M = inicializarMatriz(tamanhoMatriz);

  // TESTE DRIVE
  this->tamanhoMatriz = 3;
  M[0][0] = 1;
  M[0][1] = -3;
  M[0][2] = 2;
  M[1][0] = -2;
  M[1][1] = 8;
  M[1][2] = -1;
  M[2][0] = 4;
  M[2][1] = -6;
  M[2][2] = 5;

  // AVION E VITOR RECEBER A MATRIZ
}

double** inicializarMatriz(int tamanhoMatriz)
{
  double** Matriz = (double**) malloc(sizeof(double*) * tamanhoMatriz);

  for (int i = 0; i < tamanhoMatriz; i++)
  {
    Matriz[i] = (double*) malloc(sizeof(double) * tamanhoMatriz);
  }

  return Matriz;
}