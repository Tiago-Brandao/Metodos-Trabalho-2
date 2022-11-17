#include "../include/metodo.h"

Metodo::Metodo(){}

Metodo::Metodo(int tamanhoMatriz, bool pivoParcial)
{
  this->tamanhoMatriz = tamanhoMatriz;
  this->M = inicializarMatriz(tamanhoMatriz);
  this->pivoParcial = pivoParcial;
}

Metodo::Metodo(double**matriz, int tamanhoMatriz, bool pivoParcial){
  this->tamanhoMatriz = tamanhoMatriz;
  this->M = inicializarMatriz(tamanhoMatriz);
  this->pivoParcial = pivoParcial;

  this->M = matriz;
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

double** prodMM(double** A, double** B, int tamanhoMatriz)
{
  double** Mult = inicializarMatriz(tamanhoMatriz);

  for (int linhaMult = 0; linhaMult < tamanhoMatriz; linhaMult++)
  {
    for (int colunaMult = 0; colunaMult < tamanhoMatriz; colunaMult++)
    {
      Mult[linhaMult][colunaMult] = 0;

      for(int colunaA = 0; colunaA < tamanhoMatriz; colunaA++)
      {
        Mult[linhaMult][colunaMult] += A[linhaMult][colunaA] * B[colunaA][colunaMult];
      }
    }
  }

  return Mult;
}

double* prodMV(double** M, double *V, int n)
{
  double* prod = (double *) malloc(sizeof(double) * n);

  for (int i = 0; i < n; i++)
  {
    prod[i] = 0;
    for (int j = 0; j < n; j++)
    {
      prod[i] += M[i][j] * V[j];
    }
  }

  return prod;
}

void Metodo::setM(double** matriz){
  this->M = matriz;
}