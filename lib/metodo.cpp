#include "../include/metodo.h"

Metodo::Metodo(){}

Metodo::Metodo(int tamanhoMatriz, bool pivoParcial)
{
  this->tamanhoMatriz = tamanhoMatriz;
  this->M = inicializarMatriz(tamanhoMatriz);
  this->pivoParcial = pivoParcial;
  
  // TESTE DRIVE
  this->tamanhoMatriz = 3;

  /*
  M[0][0] = 1;
  M[0][1] = -3;
  M[0][2] = 2;
  M[1][0] = -2;
  M[1][1] = 8;
  M[1][2] = -1;
  M[2][0] = 4;
  M[2][1] = -6;
  M[2][2] = 5;
  */

  /*
  M[0][0] = 3;
  M[0][1] = -4;
  M[0][2] = 1;
  M[1][0] = 1;
  M[1][1] = 2;
  M[1][2] = 2;
  M[2][0] = 4;
  M[2][1] = 0;
  M[2][2] = -3;
  */

  M[0][0] = 3;
  M[0][1] = 2;
  M[0][2] = 4;
  M[1][0] = 1;
  M[1][1] = 1;
  M[1][2] = 2;
  M[2][0] = 4;
  M[2][1] = 3;
  M[2][2] = -2;


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