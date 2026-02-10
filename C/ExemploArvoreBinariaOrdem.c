#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Sala{
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
};

struct Sala* criarNo(char* valor){
    struct Sala* novo = (struct Sala*) malloc(sizeof(struct Sala));

    strcpy(novo->nome, valor);

    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

void liberar(struct Sala* raiz){
    if(raiz != NULL){
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

void preOrdem(struct Sala* raiz){
    if(raiz != NULL){
        printf("%s ", raiz->nome);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(struct Sala* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->nome);
        emOrdem(raiz->direita);
    }
}

void posOrdem(struct Sala* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->nome);
    }
}

int main(){
    struct Sala* raiz = criarNo("Hall de Entrada");

    raiz->esquerda = criarNo("Sala de Estar");

    raiz->direita = criarNo("Biblioteca");

    raiz->esquerda->esquerda = criarNo("Quarto");

    printf("Pré-ordem: "); preOrdem(raiz); printf("\n");

    printf("Em ordem: "); emOrdem(raiz); printf("\n");

    printf("Pós-ordem: "); posOrdem(raiz); printf("\n");

    liberar(raiz);

    return 0;
}