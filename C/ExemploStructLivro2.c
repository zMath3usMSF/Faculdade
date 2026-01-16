#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};

struct Emprestimo {
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));
    
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL){
        printf("Erro: Falha ao alocar memoria.\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do {
        printf("=============================================\n");
        printf("    BIBLIOTECA - PARTE 2\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar emprestimo\n");
        printf("4 - Listar emprestimos\n");
        printf("0 - Sair\n");
        printf("---------------------------------------------\n");
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

                    biblioteca[totalLivros].disponivel = 1;

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
            case 3:
                printf("--- Realizar Emprestimo ---\n\n");

                if(totalEmprestimos >= MAX_EMPRESTIMOS){
                    printf("Limite de emprestimos atingido!\n");
                } else {
                    printf("Livros disponiveis:\n");
                    int disponiveis = 0;
                    for (int i = 0; i < totalLivros; i++){
                        if (biblioteca[i].disponivel){
                            printf("%d - %s\n", i + 1, biblioteca[i].nome);
                            disponiveis++;
                        }
                    }

                    if (disponiveis == 0) {
                        printf("Nenhum livro disponivel para emprestimo.\n");
                    } else {
                        printf("\nDigite o numero do livro que desja emprestar: ");
                        int numLivro;
                        scanf("%d", &numLivro);
                        limparBufferEntrada();

                        int indice = numLivro - 1;

                        if(indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel){
                            printf("Digite o nome do usuario que esteja pegando o livro: ");
                            fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                            emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';

                            emprestimos[totalEmprestimos].indiceLivro = indice;

                            biblioteca[indice].disponivel = 0;

                            totalEmprestimos++;
                            printf("\nEmprestimo realizado com sucesso!\n");
                        } else {
                            printf("\nNumero de livro invalido ou livro indisponivel.\n");
                        }
                    }
                }
                printf("\nPressione ENTER para continuar...");
                getchar();
                break;
            
            case 4:
                printf("--- Lista de Emprestimos ---\n\n");
                if (totalEmprestimos == 0){
                    printf("Nenhum emprestimo realizado.\n");
                } else {
                    for (int i = 0; i < totalEmprestimos; i++){
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("----------------------------------------------\n");
                        printf("EMPRESTIMO %d\n", i + 1);
                        printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
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

    free(biblioteca);
    free(emprestimos);

    printf("Memoria liberada com sucesso.\n");
    
    return 0;
}