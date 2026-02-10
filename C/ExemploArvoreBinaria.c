#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

Sala* criarSala(const char* valor){
    Sala* novo = (Sala*)malloc(sizeof(Sala));
    if(novo == NULL){
        printf("Erro ao alocar memória!\n");
    }
    strcpy(novo->nome, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

Sala* inserirSala(Sala* raiz, const char* valor){
    if(raiz == NULL){
        return criarSala(valor);
    }
    if(strcmp(valor, raiz->nome) < 0){
        raiz->esquerda = inserirSala(raiz->esquerda, valor);
    }else{
        raiz->direita = inserirSala(raiz->direita, valor);
    }

    return raiz;
}

void preOrdem(Sala* raiz){
    if(raiz != NULL){
        printf("%s ", raiz->nome);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(Sala* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->nome);
        emOrdem(raiz->direita);
    }
}

void posOrdem(Sala* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->nome);
    }
}

void liberar(Sala* raiz){
    if(raiz != NULL){
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

int main(){
    Sala* raiz = NULL;

    raiz = inserirSala(raiz, "Hall de Entrada");
    raiz = inserirSala(raiz, "Sala de Estar");
    raiz = inserirSala(raiz, "Biblioteca");
    raiz = inserirSala(raiz, "Quarto");

    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    liberar(raiz);

    return 0;
}