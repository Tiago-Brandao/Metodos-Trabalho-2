#include "../include/ldp.h"
#include "../include/pivot.h"

LDP::LDP(){

}

LDP::LDP(double** matriz, int tamanhoMatriz, bool pivoParcial):Metodo(matriz, tamanhoMatriz, pivoParcial){
    this->inicializar();
};

void LDP::inicializar(){
    this->L = inicializarMatriz(tamanhoMatriz);
    this->D = inicializarMatriz(tamanhoMatriz);
    this->P = inicializarMatriz(tamanhoMatriz);

    for (int i = 0; i < tamanhoMatriz; i++){
        for (int j = 0; j < tamanhoMatriz; j++){
            this->L[i][j] = 0;
            this->D[i][j] = 0;
            this->P[i][j] = this->M[i][j];
        }
    }
};

void LDP::calcularLDP(){
    double razao;
    double pivo;
    int n = this->tamanhoMatriz;
    Pivot pivotar;

    if (pivoParcial){
        pivotar = Pivot(this->M, tamanhoMatriz);
    }

    for (int coluna = 0; coluna < n - 1; coluna++){

        if (pivoParcial){
            pivotar.pivotacaoParcial(this->P, coluna, tamanhoMatriz);
            this->P = pivotar.matriz;
            this->Permutation = pivotar.permutation;
        }

        pivo = this->P[coluna][coluna];

        this->D[coluna][coluna] = pivo;

        for (int linha = coluna + 1; linha < n; linha++){
            razao = this->P[linha][coluna] / pivo;
            
            this->L[linha][coluna] = razao;
            this->P[coluna][coluna] = 0;
            this->P[linha][coluna] = 0;

            for (int k = coluna + 1; k < n; k++){
                this->P[linha][k] = razao * (-1) * this->P[coluna][k] + this->P[linha][k];
            }
        }

    }

    this->D[n-1][n-1] = this->P[n-1][n-1];
    this->P[n-1][n-1] = 0;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            this->P[i][j] /= this->D[i][i];
        }
    }

    for (int i = 0; i < n; i++){
        this->L[i][i] = 1;
        this->P[i][i] = 1;
    }
}

void LDP::substituicao(double* v){
    int n = tamanhoMatriz;
    
    this->vetorResolucao = v;

    if (pivoParcial){
        this->vetorResolucao = prodMV(Permutation, v, tamanhoMatriz);
    }

    // Lz = v
    for (int i = 0; i < tamanhoMatriz; i++){

        for (int j = 0; j < i; j++){
            vetorResolucao[i] -= L[i][j] * vetorResolucao[j];
        }
    }

    // Dy = z
    for (int i = 0; i < tamanhoMatriz; i++){
        this->vetorResolucao[i] /= D[i][i];
    }

    // Px = y
    for (int i = tamanhoMatriz - 1; i >= 0; i--){
        for (int j = i + 1; j < tamanhoMatriz; j++){
            this->vetorResolucao[i] -= P[i][j] * vetorResolucao[j];
        }
    }
};

double* LDP::calcularMetodo(double* v){
    substituicao(v);
    return vetorResolucao;
}
