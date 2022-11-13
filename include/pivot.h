#pragma once

class Pivot{
public:
    double** matriz;

    Pivot();

    Pivot(double** matriz);

    double** pivotacaoParcial(double** matriz, int index, int tamanhoMatriz);

    void trocarLinhas(int linha1, int linha2);
};