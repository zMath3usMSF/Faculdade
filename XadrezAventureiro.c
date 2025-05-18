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
    printf("\nBispo:\n");
    for(int i = 1; i <= 5; i++){
        printf("Direita\n");
        printf("Cima\n");
    }

    /*
        Rainha: Fazer a movimentação da Rainha de 8 casas para a esquerda.
    */
    printf("\nRainha:\n");
    for(int i = 1; i <= 8; i++){
        printf("Esquerda\n");
    }


    /*
        Cavalo: Fazer a movimentação do Cavalo de 2 casas para a baixo e 1 para esquerda.
    */
    printf("\nCavalo:\n");
    for(int i = 1; i <= 2; i++){
        printf("Baixo\n");
        while(i == 2){
            printf("Esquerda\n");
            i++;
        }
    }
}