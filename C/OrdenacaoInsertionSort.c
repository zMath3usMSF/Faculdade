#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int vetor[], int tamanho);

int main(){
    int vetor[9] = {4, 2, 5, 1, 3, 6, 9, 8, 7};
    printf("Vetor antes do Insertion Sort:");
    for(int i = 0; i < 9; i++){
        printf(" %d", vetor[i]);
    }
    printf("\n");

    insertionSort(vetor, 9);

    printf("Vetor depois do Insertion Sort:");
    for(int i = 0; i < 9; i++){
        printf(" %d", vetor[i]);
    }
    printf("\n");
}

void insertionSort(int vetor[], int tamanho){
    for(int i = 1; i < tamanho; i++){
        int chave = vetor[i];
        int j = i - 1;

        while(j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j--;
        }
    
        vetor[j + 1] = chave;
    }
}