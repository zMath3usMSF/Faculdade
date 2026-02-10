#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct ArvorePistas{
    char pista[50];
    struct ArvorePistas* esquerda;
    struct ArvorePistas* direita;
}ArvorePistas;

ArvorePistas* criarArvorePistas(const char* valor){
    ArvorePistas* novo = (ArvorePistas*)malloc(sizeof(ArvorePistas));
    strcpy(novo->pista, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

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

bool buscarBST(ArvorePistas* raiz, const char* chave){
    if(raiz == NULL){
        return false;
    }
    if(strcmp(chave, raiz->pista) == 0){
        return true;
    }
    if(strcmp(chave, raiz->pista) < 0){
        return buscarBST(raiz->esquerda, chave);
    }
    else{
        return buscarBST(raiz->direita, chave);
    }
}

void exibirPistas(ArvorePistas* raiz){
    if(raiz != NULL){
        exibirPistas(raiz->esquerda);
        printf("%s ", raiz->pista);
        exibirPistas(raiz->direita);
    }
}

void liberarArvoreDePistas(ArvorePistas* raiz){
    if(raiz != NULL){
        liberarArvoreDePistas(raiz->esquerda);
        liberarArvoreDePistas(raiz->direita);
        free(raiz);
    }
}

int main(){
    printf("\n==== BST ====\n");
    ArvorePistas* raizBST = NULL;
    raizBST = inserirPista(raizBST, "Pegadas de Lama");
    raizBST = inserirPista(raizBST, "Chave perdida");
    raizBST = inserirPista(raizBST, "Livro com pagina faltando");
    raizBST = inserirPista(raizBST, "Lencol manchado");
    raizBST = inserirPista(raizBST, "Gaveta perdida");

    printf("Em ordem (BST): ");
    exibirPistas(raizBST);
    printf("\nBuscar 'Lencol manchado' (BST): %s\n", buscarBST(raizBST, "Lencol manchado") ? "Encontrado" : "Nao encontrado");
    printf("Buscar 'Oculos' (BST): %s\n", buscarBST(raizBST, "Oculos") ? "Encontrado" : "Nao encontrado");

    liberarArvoreDePistas(raizBST);
}