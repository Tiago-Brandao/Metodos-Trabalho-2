#include "../include/lu.h"

LU::LU()
{}

LU::LU(int tamanhoMatriz):Metodo(tamanhoMatriz)
{
  this->inicializar();
};

void LU::inicializar()
{
  this->L = inicializarMatriz(tamanhoMatriz);
  this->U = inicializarMatriz(tamanhoMatriz);

  // ALIMENTANDO L e U
  for(int i = 0; i < tamanhoMatriz; i++)
  {
    for(int j = 0; j < tamanhoMatriz; j++)
    {
      this->U[i][j] = this->M[i][j];

      if (i != j)
      {
        this->L[i][j] = 0;
      }

      else
      {
        this->L[i][j] = 1;
      }
    }
  }

  this->calcLU();
}

void LU::calcLU()
{
  double PIVO;
  double RAZAO;
  int k, coluna, linha;
  int n = tamanhoMatriz;

  for(coluna = 0; coluna < (n-1); coluna++)
  {
    for(linha = coluna+1; linha < n; linha++)
    {
      RAZAO = U[linha][coluna] / U[coluna][coluna];

      L[linha][coluna] = RAZAO;

      for(k = coluna; k < n; k++)
      {
        // pivo = u[(tamanhoMatriz * coluna) + k];
        PIVO = U[coluna][k];

        // u[(tamanhoMatriz * linha) + k] -= razao*pivo;

        U[linha][k] -= RAZAO * PIVO;
      }
    }
  }
}

double* LU::calcularMetodo(double* b)
{
  cout << "L\n";
  for(int i = 0; i < tamanhoMatriz; i++)
  {
    for(int j = 0; j < tamanhoMatriz; j++)
    {
      cout << L[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\nU\n";
  for(int i = 0; i < tamanhoMatriz; i++)
  {
    for(int j = 0; j < tamanhoMatriz; j++)
    {
      cout << U [i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\nM\n";
  for(int i = 0; i < tamanhoMatriz; i++)
  {
    for(int j = 0; j < tamanhoMatriz; j++)
    {
      cout << M[i][j] << " ";
    }
    cout << "\n";
  }

  return b;
}