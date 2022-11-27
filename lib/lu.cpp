#include "../include/lu.h"

LU::LU()
{}

LU::LU(double** matriz, int tamanhoMatriz, bool pivoParcial):Metodo(matriz, tamanhoMatriz, pivoParcial)
{
  this->inicializar();
};

void LU::inicializar()
{
  this->valido = true;
  this->L = inicializarMatriz(tamanhoMatriz);
  this->U = inicializarMatriz(tamanhoMatriz);
  this->P = inicializarMatriz(tamanhoMatriz);

  // Inicializando os elementos de  L, U e P
  for(int i = 0; i < tamanhoMatriz; i++)
  {
    for(int j = 0; j < tamanhoMatriz; j++)
    {
      this->U[i][j] = this->M[i][j];
      this->L[i][j] = 0;

      if (i != j)
      {
        this->P[i][j] = 0;
      }

      else
      {
        this->P[i][j] = 1;
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
  bool pivo_Parcial_ja_foi_feito;

  for(coluna = 0; coluna < (n-1); coluna++)
  {
    if (!valido)
    {
      break;
    }

    pivo_Parcial_ja_foi_feito = false;
    for(linha = coluna+1; linha < n; linha++)
    {
      // Cálculo da razão e, em caso de pivotação parcial, mudança das linhas
      RAZAO = calcRazao(linha, coluna, pivo_Parcial_ja_foi_feito);

      if (!valido)
      {
        break;
      }

      pivo_Parcial_ja_foi_feito = true;

      L[linha][coluna] = RAZAO;

      // L_indice_linha - (L_indice_coluna * RAZAO)
      for(k = coluna; k < n; k++)
      {
        PIVO = U[coluna][k];
        U[linha][k] -= RAZAO * PIVO;
      }
    }
  }

  if (valido)
  {
    // Corrigindo L
    for (int i = 0; i < n; i++)
    {
      L[i][i] = 1;
    }
  }
}

// Troca as linhas de lugar na pivotação parcial
void LU::trocarLinhas(int linha1, int linha2)
{
  double* Ulinha1 = U[linha1];
  double* Ulinha2 = U[linha2];

  double* Plinha1 = P[linha1];
  double* Plinha2 = P[linha2];

  double* Llinha1 = L[linha1];
  double* Llinha2 = L[linha2];

  U[linha1] = Ulinha2;
  U[linha2] = Ulinha1;

  P[linha1] = Plinha2;
  P[linha2] = Plinha1;

  L[linha1] = Llinha2;
  L[linha2] = Llinha1;
}

double LU::calcRazao(int i, int j, bool pivo_Parcial_ja_foi_feito)
{
  if((pivoParcial) && (!pivo_Parcial_ja_foi_feito))
  {
    double pivo = U[j][j];
    int linha1 = j;
    int linha2 = 0;

    for(int linha = j+1; linha < tamanhoMatriz; linha++)
    {
      if (abs(U[linha][j]) > abs(pivo))
      {
        pivo = U[linha][j];
        linha2 = linha;
      }
    }

    if (linha2 > 0)
    {
      this->trocarLinhas(linha1, linha2);
    }
  }

  if (U[j][j] == 0)
  {
    valido = false;
    return 0;
  }

  return (U[i][j] / U[j][j]);
}

double* LU::calcularMetodo(double* b)
{
  if (!valido)
  {
    return nullptr;
  }

  return calcX(calcY(b));
}

double* LU::calcY(double* b)
{
  int n = tamanhoMatriz;
  double* bMod = b;

  if (pivoParcial)
  {
    bMod = prodMV(P, b, n);
    free(b);
  }

  double* y = (double *) malloc(sizeof(double) * n);

  for(int i = 0; i < n; i++)
  {
    y[i] = bMod[i];

    for(int j = 0; j < i; j++)
    {
      y[i] -= L[i][j] * y[j];
    }
  }

  return y;
}

double* LU::calcX(double* y)
{
  int n = tamanhoMatriz;

  double* x = (double *) malloc(sizeof(double) * n);

  for(int i = n-1; i > -1; i--)
  {
    x[i] = y[i];

    for(int j = n-1; j > i; j--)
    {
      x[i] -= U[i][j] * x[j];
    }

    x[i] = x[i] / U[i][i];
  }

  return x;
}
