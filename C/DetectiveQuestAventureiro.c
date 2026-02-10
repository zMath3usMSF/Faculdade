// Módulos
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Estrutura da Sala
typedef struct Sala{
    char nome[50];
    char pista[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// Estrutura da Árvore de Pistas
typedef struct ArvorePistas{
    char pista[50];
    struct ArvorePistas* esquerda;
    struct ArvorePistas* direita;
}ArvorePistas;

// Função que Limpa o Buffer de Entrada
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Função que Cria a Sala
Sala* criarSala(const char* valor, const char* pista){
    Sala* novo = (Sala*)malloc(sizeof(Sala));
    if(novo == NULL){
        printf("Erro ao alocar memoria!\n");
    }
    strcpy(novo->nome, valor);
    strcpy(novo->pista, pista);
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    return novo;
}

// Função que cria a Árvore de Pistas
ArvorePistas* criarArvorePistas(const char* valor){
    ArvorePistas* novo = (ArvorePistas*)malloc(sizeof(ArvorePistas));
    strcpy(novo->pista, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função que Insere uma Nova Sala no Lado Direito ou Lado Esquerdo
Sala* inserirSala(Sala* raiz, const char* valor, const char* pista){
    if(raiz == NULL){
        return criarSala(valor, pista);
    }
    if(strcmp(valor, raiz->nome) < 0){
        raiz->esquerda = inserirSala(raiz->esquerda, valor, pista);
    }else{
        raiz->direita = inserirSala(raiz->direita, valor, pista);
    }
    
    return raiz;
}

// Função que insere Pista na Árvore de Pistas
ArvorePistas* inserirPista(ArvorePistas* raiz, const char* valor){
    if(raiz == NULL){
        return criarArvorePistas(valor);
    }
    if(strcmp(valor, raiz->pista) < 0){
        raiz->esquerda = inserirPista(raiz->esquerda, valor);
    }
    else{
        raiz->direita = inserirPista(raiz->direita, valor);
    }
    return raiz;
}

// Função que Libera a Árvore de Salas
void liberarArvoreDeSalas(Sala* raiz){
    if(raiz != NULL){
        liberarArvoreDeSalas(raiz->esquerda);
        liberarArvoreDeSalas(raiz->direita);
        free(raiz);
    }
}

// Função que Busca a Pista na Árvore de Pistas
bool buscarPista(ArvorePistas* raiz, const char* chave){
    if(raiz == NULL){
        return false;
    }
    if(strcmp(chave, raiz->pista) == 0){
        return true;
    }
    if(strcmp(chave, raiz->pista) < 0){
        return buscarPista(raiz->esquerda, chave);
    }
    else{
        return buscarPista(raiz->direita, chave);
    }
}

// Função que exibe as Pistas na Árvore de Pistas
void exibirPistas(ArvorePistas* raiz){
    if(raiz != NULL){
        exibirPistas(raiz->esquerda);
        printf("%s\n", raiz->pista);
        exibirPistas(raiz->direita);
    }
}

// Função que Libera a Árvore de Pistas da Memória
void liberarArvoreDePistas(ArvorePistas* raiz){
    if(raiz != NULL){
        liberarArvoreDePistas(raiz->esquerda);
        liberarArvoreDePistas(raiz->direita);
        free(raiz);
    }
}

// Função que Verifica se a Sala possui Pista
void verificarPista(Sala* raiz, ArvorePistas* pistas){
    if((strcmp(raiz->pista, "") != 0) && buscarPista(pistas, raiz->pista) == false){
        printf("Pista encontrada: %s\n", raiz->pista);
        inserirPista(pistas, raiz->pista);
        strcpy(raiz->pista, "");
    }
}

// Função que Explora as Salas
void explorarSalasComPistas(Sala* raiz, ArvorePistas* pistas){
    int opcao;
    do{
        printf("\n===============================================\n");
        printf("             DETECTIVE QUEST - NOVATO            \n");
        printf("=================================================\n");
        printf("Sala Atual: %s\n", raiz->nome);
        verificarPista(raiz, pistas);
        printf("\n1 - Ir para o lado esquerdo\n");
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
                printf("\nPistas encontradas:");
                exibirPistas(pistas);
                printf("\nPressione ENTER para continuar...");
                getchar();
                printf("\nSaindo...\n");
                opcao = 0;
                break;
            default:
                break;
        }
        limparBufferEntrada();
    }while(opcao != 0);
}

int main(){
    Sala* raiz = criarSala("Hall de Entrada", "");
    ArvorePistas* pistas = criarArvorePistas("");

    inserirSala(raiz, "Quintal", "Motoserra");
    inserirSala(raiz, "Sala de Estar", "Porta solta");
    inserirSala(raiz, "Biblioteca", "Livros derrubados");
    inserirSala(raiz, "Quarto", "Cama baguncada");
    inserirSala(raiz, "Cozinha", "Torneira aberta");
    inserirSala(raiz, "Banheiro", "Chuveiro aberto");

    explorarSalasComPistas(raiz, pistas);

    liberarArvoreDeSalas(raiz);
    liberarArvoreDePistas(pistas);
    return 0;
}