#include "../include/pivot.h"

Pivot::Pivot(){}

Pivot::Pivot(double** matriz){
    this->matriz = matriz;
}

double** Pivot::pivotacaoParcial(double** matriz, int index, int tamanhoMatriz){
    int indexMax = index;

    for(int i = index+1; i < tamanhoMatriz; i++){
        if(indexMax < matriz[i][index]){
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
}