#include "../include/pivot.h"

Pivot::Pivot(){}

Pivot::Pivot(double** matriz, int tamanhoMatriz){
    this->matriz = matriz;
    this->permutation = (double**) malloc(sizeof(double*) * tamanhoMatriz);

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        permutation[i] = (double*) malloc(sizeof(double) * tamanhoMatriz);

        for (int j = 0; j < tamanhoMatriz; j++){
            permutation[i][j] = 0;
        }

        permutation[i][i] = 1;
    }
}

double** Pivot::pivotacaoParcial(double** matriz, int index, int tamanhoMatriz){
    int indexMax = index;

    for(int i = index+1; i < tamanhoMatriz; i++){
        if(abs(matriz[indexMax][index]) < abs(matriz[i][index])){
            indexMax = i;
        }
    }

    if(indexMax != index){
        this->trocarLinhas(indexMax, index);
    }

    return matriz;
}

void Pivot::trocarLinhas(int linha1, int linha2){
  double* Mlinha1 = this->matriz[linha1];
  double* Mlinha2 = this->matriz[linha2];

  this->matriz[linha1] = Mlinha2;
  this->matriz[linha2] = Mlinha1;

  Mlinha1 = this->permutation[linha1];
  Mlinha2 = this->permutation[linha2];

  this->permutation[linha1] = Mlinha2;
  this->permutation[linha2] = Mlinha1;
}
