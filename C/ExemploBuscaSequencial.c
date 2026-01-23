#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaSequencial(int vetor[], int tamanho, int valor);

int main(){
    int vetor[10] = {8, 14, 19, 29, 44, 61, 63, 74, 82, 90};
    int indice = buscaSequencial(vetor, 10, 61);

    return 1;
}

int buscaSequencial(int vetor[], int tamanho, int valor){
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] == valor){
            return i;
        }
    }

    return -1;
}