#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int opcao;
    int numeroSecreto, palpite;
    printf("Menu Principal\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao)
    {
        case 1:
            srand(time(0));
            numeroSecreto = rand() % 10;
            printf("Digite um número de 0 a 9: ");
            scanf("%d", &palpite);
            if(numeroSecreto == palpite){
                printf("Você acertou!\n");
            }else{
                printf("Você errou!\n");
            }
            printf("O Número secreto era %d\n", numeroSecreto);
            break;
        case 2:
            printf("Regras do Jogo:\n");
            break;
        case 3:
            printf("Saindo do Jogo...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}