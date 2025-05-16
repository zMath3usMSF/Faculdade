#include <stdio.h>

int main(){
    int menu = 0;
    int menu1 = 0;

    do{
        printf("Menu Principal:\n");
        printf("1. Página 1\n");
        printf("2. Sair\n");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                do{printf("Menu Página 1:\n");
                printf("1. Jogar\n");
                printf("2. Voltar\n");
                scanf("%d", &menu1);
                switch(menu1){
                    case 1:
                        printf("Jogando...\n");
                        menu1 = 0;
                        break;
                    case 2:
                        printf("Voltando...\n");
                        menu = 0;
                        menu1 = -1;
                    default:
                        printf("Opção inválida.\n");
                        break;
                }
                }while(menu1 != -1);  
                break;
            case 2:
                printf("Encerrando o programa...\n");
                menu = -1;
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }while(menu != -1);
}