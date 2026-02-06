#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No{
    char valor[50];
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(const char* valor){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria!\n");
    }
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    return novo;
}

No* inserir(No* raiz, const char* valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
    if(strcmp(valor, raiz->valor) < 0){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }else{
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    return raiz;
}

int main(){
    No* raiz = NULL;

    inserir(raiz, "Hall de Entrada");
    inserir(raiz, "Sala de Estar");
    inserir(raiz, "Biblioteca");
    inserir(raiz, "Quarto");

    int opcao;
    do{

    }while(opcao != 0);


    return 0;
}