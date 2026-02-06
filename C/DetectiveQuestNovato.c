// Módulos
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Estrutura da Sala
typedef struct Sala{
    char valor[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// Função que Limpa o Buffer de Entrada
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Função que Cria a Sala
Sala* criarSala(const char* valor){
    Sala* novo = (Sala*)malloc(sizeof(Sala));
    if(novo == NULL){
        printf("Erro ao alocar memoria!\n");
    }
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    return novo;
}

// Função que Insere uma Nova Sala no Lado Direito ou Lado Esquerdo
Sala* inserirSala(Sala* raiz, const char* valor){
    if(raiz == NULL){
        return criarSala(valor);
    }
    if(strcmp(valor, raiz->valor) < 0){
        raiz->esquerda = inserirSala(raiz->esquerda, valor);
    }else{
        raiz->direita = inserirSala(raiz->direita, valor);
    }
    
    return raiz;
}

// Função que Explora as Salas
void explorarSalas(Sala* raiz){
    int opcao;
    do{
        printf("\n===============================================\n");
        printf("             DETECTIVE QUEST - NOVATO            \n");
        printf("=================================================\n");
        printf("Sala Atual: %s\n\n", raiz->valor);
        printf("1 - Ir para o lado esquerdo\n");
        printf("2 - Ir para o lado direito\n");
        printf("0 - Sair\n");
        printf("--------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("Indo para a esquerda...\n");
                if(raiz->esquerda != NULL){
                    raiz = raiz->esquerda;
                }else{
                    printf("OPSSS! Não existe sala no lado esquerdo\n");
                    printf("\nPressione ENTER para continuar...");
                    getchar();
                }
                break;
            case 2:
                printf("Indo para a direita...\n");
                if(raiz->direita != NULL){
                    raiz = raiz->direita;
                }else{
                    printf("OPSSS! Não existe sala no lado direito\n");
                    printf("\nPressione ENTER para continuar...");
                    getchar();
                }
                break;
            case 0:
                printf("Saindo...\n");
                opcao = 0;
                break;
            default:
                break;
        }
        limparBufferEntrada();
    }while(opcao != 0);
}

int main(){
    Sala* raiz = criarSala("Hall de Entrada");

    inserirSala(raiz, "Sala de Estar");
    inserirSala(raiz, "Biblioteca");
    inserirSala(raiz, "Quarto");

    explorarSalas(raiz);

    return 0;
}