#include "../include/lu.h"

LU::LU()
{}

LU::LU(int tamanhoMatriz, bool pivoParcial):Metodo(tamanhoMatriz, pivoParcial)
{
  this->inicializar();
};

void LU::inicializar()
{
  this->L = inicializarMatriz(tamanhoMatriz);
  this->U = inicializarMatriz(tamanhoMatriz);
  this->P = inicializarMatriz(tamanhoMatriz);

  // ALIMENTANDO L e U
  for(int i = 0; i < tamanhoMatriz; i++)
  {
    for(int j = 0; j < tamanhoMatriz; j++)
    {
      this->U[i][j] = this->M[i][j];

      if (i != j)
      {
        this->L[i][j] = 0;
        this->P[i][j] = 0;
      }

      else
      {
        this->L[i][j] = 1;
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

  for(coluna = 0; coluna < (n-1); coluna++)
  {
    // CORRIGIR O L QUANDO FOR PIVO PARCIAL!
    // AINDA NÃO SEI COMO FAZER!
    if (pivoParcial)
    {
      double **Lmod = prodMM(P, L, n);
      free(L);
      L = Lmod;
    }
    
    for(linha = coluna+1; linha < n; linha++)
    {
      //RAZAO = U[linha][coluna] / U[coluna][coluna];
      RAZAO = calcRazao(linha, coluna);

      L[linha][coluna] = RAZAO;

      for(k = coluna; k < n; k++)
      {
        PIVO = U[coluna][k];
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

  return calcX(calcY(b));
}

void LU::trocarLinhas(int linha1, int linha2)
{
  double* Ulinha1 = U[linha1];
  double* Ulinha2 = U[linha2];

  double* Plinha1 = P[linha1];
  double* Plinha2 = P[linha2];

  U[linha1] = Ulinha2;
  U[linha2] = Ulinha1;

  P[linha1] = Plinha2;
  P[linha2] = Plinha1;
}

void LU::mudarL(int linha1, int linha2)
{
  double* Llinha1 = L[linha1];
  double* Llinha2 = L[linha2];

  L[linha1] = Llinha2;
  L[linha2] = Llinha1;
}

double LU::calcRazao(int i, int j)
{
  if(pivoParcial)
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
      /*
      double razao = (U[i][j]/ U[j][j]);
      L[i][j] = razao;
      this->mudarL(linha1, linha2);
      */
    }
  }

  // RAZAO = U[linha][coluna] / U[coluna][coluna];
  return (U[i][j] / U[j][j]);
}

double* LU::calcY(double* b)
{
  int n = tamanhoMatriz;
  double* bReal = b;
  if (pivoParcial)
  {
    bReal = prodMV(P, b, n);
    free(b);
  }

  double* y = (double *) malloc(sizeof(double) * n);

  for(int i = 0; i < n; i++)
  {
    y[i] = bReal[i];

    for(int j = 0; j < i; j++)
    {
      y[i] -= L[i][j] * y[j];
    }
  }

  cout << "\ny:\n";
  for (int i = 0; i < n; i++)
  {
    cout << y[i] << "\n";
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

  cout << "\nx:\n";
  for (int i = 0; i < n; i++)
  {
    cout << x[i] << "\n";
  }

  return x;
}