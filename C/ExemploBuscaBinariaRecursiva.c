#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor);

int main(){
    int vetor[10] = {8, 14, 19, 29, 44, 61, 63, 74, 82, 90};
    int indice = buscaBinariaRecursiva(vetor, 0, 9, 61);
    return 1;
}

int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor){
    if(inicio > fim){
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;

    if(vetor[meio] == valor){
        return meio;
    }

    else if(vetor[meio] < valor){
        return buscaBinariaRecursiva(vetor, meio + 1, fim, valor);
    }
    else{
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor);
    }
}