#include <stdlib.h>
#include <stdio.h>

struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
}

int altura(struct No* raiz){
    if(raiz == NULL){
        return 0;
    }

    int alt_esq = altura(raiz->esquerda);

    int alt_dir = altura(raiz->direita);

    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}

int profundidade(struct No* raiz, struct No* alvo, int nivel){
    if(raiz == NULL){
        return -1;
    }

    if(raiz == alvo){
        return nivel;
    }

    int esq = profundidade(raiz->esquerda, alvo, nivel + 1);
    if(esq != -1){
        return esq;
    }

    return profundidade(raiz->direita, alvo, nivel + 1);
}

int main(){
    return 0;
}