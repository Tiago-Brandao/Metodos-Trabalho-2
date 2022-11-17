#pragma once
#include "./metodo.h"
using std::cout;
using std::cin;

class LDP : public Metodo {
    public:
        double** L;
        double** D;
        double** P;
        double** Permutation;
        double* vetorResolucao;

        LDP();
        LDP(int tamanhoMatriz, bool pivoParcial);
        LDP(double** matriz, int tamanhoMatriz, bool pivoParcial);

        // Alimentar as matrizes
        void inicializar();

        // Decompor a matriz em LDP
        void calcularLDP();

        // Retorna o vetorResolucao com os valores finais
        double* calcularMetodo(double *);

        // Realizar as substituições passando um vetor de valores
        void substituicao(double* v);
};
