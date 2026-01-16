#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define TAM_STRING 100

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

void limparBufferEntrada(){
    int _char;
    while((_char = getchar()) != '\n' && _char != EOF);
}

int main(){
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    do {
        printf("=============================================\n");
        printf("    BIBLIOTECA - PARTE 1\n ");
        printf("1 - Cadastrar novo Livro\n");
        printf("2 - Listar todos os Livros\n");
        printf("0 - Sair\n");
        printf("----------------------------------------------\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch(opcao){
            case 1:
                printf("--- Cadastro de Novo Livro ---\n\n");

                if(totalLivros < MAX_LIVROS){
                    printf("Digite o nome do Livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o Autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite a Editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Edigite a Edicao: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);

                    totalLivros++;

                    printf("\nLivro cadastrado com sucesso!\n");
                } else{
                    printf("Biblioteca cheia! Nao e possivel cadastrar mais livros.\n");
                }

                printf("\nPressione ENTER para continuar...");
                getchar();
                break;

            case 2:
                printf("--- Lista de Livros Cadastrados ---\n\n");

                if(totalLivros == 0){
                    printf("Nenhum Livro cadastrado ainda.\n");
                } else {
                    for(int i = 0; i < totalLivros; i++){
                        printf("----------------------------------------------\n");
                        printf("LIVRO %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                    }
                    printf("----------------------------------------------\n");
                }

                printf("\nPressione ENTER para continuar...");
                getchar();
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;    
        }
    } while (opcao != 0);

    return 0;
}