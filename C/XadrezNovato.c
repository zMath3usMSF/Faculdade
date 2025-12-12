#include <stdio.h>

int main(){
    /*
        Torre: Fazer a movimentação da Torre de 5 casas para a direita.
    */
    printf("Torre:\n");
    for(int i = 1; i <= 5; i++){
        printf("Direita\n");
    }

    /*
        Bispo: Fazer a movimentação do Bispo de 5 casas para a direita e para cima.
    */
    printf("Bispo:\n");
    for(int i = 1; i <= 5; i++){
        printf("Direita\n");
        printf("Cima\n");
    }

    /*
        Rainha: Fazer a movimentação da Rainha de 8 casas para a esquerda.
    */
    printf("Rainha:\n");
    for(int i = 1; i <= 8; i++){
        printf("Esquerda\n");
    }
}