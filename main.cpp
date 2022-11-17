#include "include/pivot.h"
#include "include/lu.h"
#include "include/ldp.h"
using std::endl;

int main(){
  int tamanhoMatriz;
  char pivotar;

  cout << "Digite o tamanho da matriz: ";
  cin >> tamanhoMatriz;

  cout << "Deseja usar pivotação parcial para resolver? (S/N): ";
  cin >> pivotar;

  if (pivotar == 'N') pivotar = 0;

  double** matriz = inicializarMatriz(tamanhoMatriz);

  for (int i = 0; i < tamanhoMatriz; i++){
    for (int j = 0; j < tamanhoMatriz; j++){
      printf("Digite o valor na posição [%d][%d] da matriz: ", i, j);
      cin >> matriz[i][j];
    }
  }

  LDP ldp = LDP(matriz, tamanhoMatriz, pivotar);

  double* vetor = (double*) malloc(sizeof(double) * tamanhoMatriz);

  for (int i = 0; i < tamanhoMatriz; i++){
    printf("Digite o valor [%d] do vetor: ", i);
    cin >> vetor[i];
  }

  ldp.calcularLDP();
  ldp.substituicao(vetor);

  // L
  cout << "----- L -----\n"; 
  for (int i = 0; i < tamanhoMatriz; i++){
    for (int j = 0; j < tamanhoMatriz; j++){
      cout << ldp.L[i][j] << " ";
    }
    cout << endl;
  }

  // D
  cout << "----- D -----\n"; 
  for (int i = 0; i < tamanhoMatriz; i++){
    for (int j = 0; j < tamanhoMatriz; j++){
      cout << ldp.D[i][j] << " ";
    }
    cout << endl;
  }

  // P
  cout << "----- P -----\n"; 
  for (int i = 0; i < tamanhoMatriz; i++){
    for (int j = 0; j < tamanhoMatriz; j++){
      cout << ldp.P[i][j] << " ";
    }
    cout << endl;
  }

  cout << "------------\n";

  // X
  cout << "X: { "; 
  for (int i = 0; i < tamanhoMatriz; i++){
    cout << ldp.vetorResolucao[i] << " ";
  }
  cout << "}\n";

  return 0;
}