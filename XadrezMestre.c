#include <stdio.h>

int main(){
    /*
        Torre: Fazer a movimentação da Torre de 5 casas para a direita.
    */
    printf("Torre\n");
    moverTorre(5);

    /*
        Bispo: Fazer a movimentação do Bispo de 5 casas para a direita e para cima.
    */
    printf("\nBispo:\n");
    int i = 0, j = 0;
    while(i < 5){
        while(j < 5){
            printf("Direita\n");
            j++;
        }
        printf("Cima\n");
        i++;
    }

    /*
        Rainha: Fazer a movimentação da Rainha de 8 casas para a esquerda.
    */
    printf("\nRainha:\n");
    moverRainha(8);

    /*
        Cavalo: Fazer a movimentação do Cavalo de 2 casas para a baixo e 1 para esquerda.
    */
    printf("\nCavalo:\n");
    for(int i = 0; i < 2; i++){
        printf("Cima\n");
        for(j = i; j == 1; j++){
            printf("Direita\n");
        }
    }
}

int moverTorre(int casas){
    if(casas > 0){
        printf("Direita\n");
        casas--;
        moverTorre(casas);
    }
}

int moverRainha(int casas){
    if(casas > 0){
        printf("Esquerda\n");
        casas--;
        moverRainha(casas);
    }
}
