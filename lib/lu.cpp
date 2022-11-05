#include "../include/lu.h"

LU::LU()
{}

LU::LU(int tamanhoMatriz):Metodo(tamanhoMatriz)
{
  this->inicializar();
};

void LU::inicializar()
{
  this->l = (double*) malloc(sizeof(double) * tamanhoMatriz * tamanhoMatriz);
  this->u = (double*) malloc(sizeof(double) * tamanhoMatriz * tamanhoMatriz);

  for(int i = 0; i < tamanhoMatriz; i++)
  {
    for(int j = 0; j < tamanhoMatriz; j++)
    {
      this->u[(tamanhoMatriz * i) + j] = this->matriz[(tamanhoMatriz * i) + j];
      if (i != j)
      {
        this->l[(tamanhoMatriz * i) + j] = 0;
      }
      else
      {
        this->l[(tamanhoMatriz * i) + j] = 1;
      }
    }
  }

  this->calcLU();
}

void LU::calcLU()
{
  double pivo;
  double razao;
  int k, coluna, linha;
  int n = tamanhoMatriz;

  for(coluna = 0; coluna < n-1; coluna++)
  {
    // primeiroPivô = u[(tamanhoMatriz * coluna) + coluna];
    for(linha = coluna+1; linha < n; linha++)
    {
      razao = u[(tamanhoMatriz * linha) + coluna] / u[(tamanhoMatriz * coluna) + coluna];
      for(k = coluna; k < n; k++)
      {
        pivo = u[(tamanhoMatriz * coluna) + k];
        u[(tamanhoMatriz * linha) + k] -= razao*pivo;

        if (linha > k)
        {
          l[(tamanhoMatriz * linha) + k] = razao;
        }
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
      cout << l[(tamanhoMatriz * i) + j] << " ";
    }
    cout << "\n";
  }

  cout << "\nU\n";
  for(int i = 0; i < tamanhoMatriz; i++)
  {
    for(int j = 0; j < tamanhoMatriz; j++)
    {
      cout << u[(tamanhoMatriz * i) + j] << " ";
    }
    cout << "\n";
  }

  return b;
}