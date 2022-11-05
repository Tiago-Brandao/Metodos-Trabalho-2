#include "../include/metodo.h"

Metodo::Metodo(){}

Metodo::Metodo(int tamanhoMatriz)
{
  /*
    ISSO TÁ CERTO. SÓ VOU COMENTAR PRA FAZER O TESTE DRIVE
    this->tamanhoMatriz = tamanhoMatriz;
    this->matriz = (double*) malloc(sizeof(double) * tamanhoMatriz * tamanhoMatriz);
  */

  
  // TESTE DRIVE
  this->tamanhoMatriz = 3;
  this->matriz = (double*) malloc(sizeof(double) * tamanhoMatriz * tamanhoMatriz);
  /*
  matriz[0] = 1;
  matriz[1] = -3;
  matriz[2] = 2;
  matriz[3] = -2;
  matriz[4] = 8;
  matriz[5] = -1;
  matriz[6] = 4;
  matriz[7] = -6;
  matriz[8] = 5;
  */

  matriz[0] = 1;
  matriz[1] = -3;
  matriz[2] = 2;
  matriz[3] = -2;
  matriz[4] = 8;
  matriz[5] = -1;
  matriz[6] = 4;
  matriz[7] = -6;
  matriz[8] = 5;


  // AVION E VITOR RECEBER A MATRIZ
}