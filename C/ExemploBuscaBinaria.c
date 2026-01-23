#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaBinaria(int vetor[], int tamanho, int valor);

int main(){
    int vetor[10] = {8, 14, 19, 29, 44, 61, 63, 74, 82, 90};
    int indice = buscaBinaria(vetor, 10, 61);

    return 1;
}

int buscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0;
    int fim = tamanho - 1;

    while(inicio <= fim){
        int meio = inicio + (fim - inicio) / 2;

        if(vetor[meio] == valor){
            return meio;
        }
        else if(vetor[meio] < valor){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }

    return -1;
}