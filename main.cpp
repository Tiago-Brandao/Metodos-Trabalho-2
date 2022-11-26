#include "include/pivot.h"
#include "include/lu.h"
#include "include/ldp.h"
#include "include/view.h"
using std::endl;

int main(){
  /* View *viewOfMenu = new View();
  LDP ldp;
  char resposta = ' ';
  double* vetor;
  int tamanhoMatriz;
  char pivotar;

  cout << "Digite o tamanho da matriz: ";
  cin >> tamanhoMatriz;

  cout << "Deseja usar pivotação parcial para resolver? (S/N): ";
  cin >> pivotar;

  if (pivotar == 'N') pivotar = 0;

  double** matriz = inicializarMatriz(tamanhoMatriz);

  while (tolower(resposta) != 'x') {
    for (int i = 0; i < tamanhoMatriz; i++){
      for (int j = 0; j < tamanhoMatriz; j++){
        printf("Digite o valor na posição [%d][%d] da matriz: ", i, j);
        cin >> matriz[i][j];
      }
    }


    ldp = LDP(matriz, tamanhoMatriz, pivotar);

    vetor = (double*) malloc(sizeof(double) * tamanhoMatriz);

    for (int i = 0; i < tamanhoMatriz; i++){
      printf("Digite o valor [%d] do vetor: ", i);
      cin >> vetor[i];
    }


    viewOfMenu->print_input_matrice(matriz, tamanhoMatriz);
    cout << "Confira a sua matriz: \n";
    cout << "Para parar digite x, para repetir o processo digite qualquer outra coisa.";
    cin >> resposta;
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

  double xx[2] = {2.5, 0.0};
  double xx2[3] = {1.0, 0.0, 1.0};


  viewOfMenu->printResultsOfMethods(ldp.vetorResolucao, xx2,  tamanhoMatriz);*/

  View *interface = new View();
  interface->menu();

  return 0;
}
