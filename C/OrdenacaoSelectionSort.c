#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(int vetor[], int tamanho);
void trocar(int* a, int* b);

int main(){
    int vetor[9] = {4, 2, 5, 1, 3, 6, 9, 8, 7};
    printf("Vetor antes do Selection Sort:");
    for(int i = 0; i < 9; i++){
        printf(" %d", vetor[i]);
    }
    printf("\n");

    selectionSort(vetor, 9);

    printf("Vetor depois do Selection Sort:");
    for(int i = 0; i < 9; i++){
        printf(" %d", vetor[i]);
    }
    printf("\n");
}

void selectionSort(int vetor[], int tamanho){
    for(int i = 0; i < tamanho - 1; i++){
        int indiceMenor = i;

        for(int j = i + 1; j < tamanho; j++){
            if(vetor[j] < vetor[indiceMenor]){
                indiceMenor = j;
            }
        }

        if(indiceMenor != i){
            trocar(&vetor[i], &vetor[indiceMenor]);
        }
    }
}

void trocar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}