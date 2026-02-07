#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct NoBST{
    char valor[50];
    struct NoBST* esquerda;
    struct NoBST* direita;
}NoBST;

NoBST* criarNoBST(const char* valor){
    NoBST* novo = (NoBST*)malloc(sizeof(NoBST));
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

NoBST* inserirBST(NoBST* raiz, const char* valor){
    if(raiz == NULL){
        return criarNoBST(valor);
    }
    if(strcmp(valor, raiz->valor) < 0){
        raiz->esquerda = inserirBST(raiz->esquerda, valor);
    }
    else{
        raiz->direita = inserirBST(raiz->direita, valor);
    }
    return raiz;
}

bool buscarBST(NoBST* raiz, const char* chave){
    if(raiz == NULL){
        return false;
    }
    if(strcmp(chave, raiz->valor) == 0){
        return true;
    }
    if(strcmp(chave, raiz->valor) < 0){
        return buscarBST(raiz->esquerda, chave);
    }
    else{
        return buscarBST(raiz->direita, chave);
    }
}

void emOrdemBST(NoBST* raiz){
    if(raiz != NULL){
        emOrdemBST(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdemBST(raiz->direita);
    }
}

void liberarBST(NoBST* raiz){
    if(raiz != NULL){
        liberarBST(raiz->esquerda);
        liberarBST(raiz->direita);
        free(raiz);
    }
}

int main(){
    printf("\n==== BST ====\n");
    NoBST* raizBST = NULL;
    raizBST = inserirBST(raizBST, "Pegadas de Lama");
    raizBST = inserirBST(raizBST, "Chave perdida");
    raizBST = inserirBST(raizBST, "Livro com pagina faltando");
    raizBST = inserirBST(raizBST, "Lencol manchado");
    raizBST = inserirBST(raizBST, "Gaveta perdida");

    printf("Em ordem (BST): ");
    emOrdemBST(raizBST);
    printf("\nBuscar 'Lencol manchado' (BST): %s\n", buscarBST(raizBST, "Lencol manchado") ? "Encontrado" : "Nao encontrado");
    printf("Buscar 'Oculos' (BST): %s\n", buscarBST(raizBST, "Oculos") ? "Encontrado" : "Nao encontrado");

    liberarBST(raizBST);
}