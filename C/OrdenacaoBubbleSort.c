#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int vetor[], int tamanho);
void trocar(int* a, int* b);

int main(){
    int vetor[9] = {4, 2, 5, 1, 3, 6, 9, 8, 7};
    printf("Vetor antes do Bubble Sort:");
    for(int i = 0; i < 9; i++){
        printf(" %d", vetor[i]);
    }
    printf("\n");

    bubbleSort(vetor, 9);

    printf("Vetor depois do Bubble Sort:");
    for(int i = 0; i < 9; i++){
        printf(" %d", vetor[i]);
    }
    printf("\n");
}

void bubbleSort(int vetor[], int tamanho){
    for(int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - 1 - i; j++){
            if(vetor[j] > vetor[j + 1]){
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

void trocar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}