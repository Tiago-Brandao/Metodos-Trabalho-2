#include "include/lu.h"
#include "include/pivot.h"

int main(){
  
  int tamanhoMatriz;
  cout << "Digite o tamanho da matriz (linhas = colunas): ";
  cin >> tamanhoMatriz;


  double** Matriz = (double**) malloc(sizeof(double*) * tamanhoMatriz);
  for (int i = 0; i < tamanhoMatriz; i++) {
    Matriz[i] = (double*) malloc(sizeof(double) * tamanhoMatriz);
  }

  for (int i = 0; i < tamanhoMatriz; i++){
    for (int j = 0; j < tamanhoMatriz; j++){
      cout << "\nDigite o valor para [" << i << "][" << j << "]";
      cin >> Matriz[i][j];
    }
  }

  for (int i = 0; i < tamanhoMatriz; i++){
    for (int j = 0; j < tamanhoMatriz; j++){
      cout <<  Matriz[i][j] << " ";
    }
    cout << "\n";
  }

  Pivot pivot(Matriz);

  Matriz = pivot.pivotacaoParcial(Matriz, 0, tamanhoMatriz);

  for (int i = 0; i < tamanhoMatriz; i++){
    for (int j = 0; j < tamanhoMatriz; j++){
      cout <<  Matriz[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}