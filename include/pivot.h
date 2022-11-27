#pragma once
#include <stdio.h>
#include <stdlib.h>

class Pivot {
public:
    double** matriz;
    double** permutation;

    Pivot();

    Pivot(double** matriz, int tamanhoMatriz);

    double** pivotacaoParcial(double** matriz, int index, int tamanhoMatriz);

    void trocarLinhas(int linha1, int linha2);
};
