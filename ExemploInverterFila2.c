#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct{
    char nome[30];
    int idade;
}Pessoa;

typedef struct{
    Pessoa pessoas[MAX];
    int inicio, fim;
}Fila;

typedef struct{
    Pessoa pessoas[MAX];
    int topo;
}Pilha;

void inicializarFila(Fila *fila){
    fila->inicio = 0;
    fila->fim = 0;
}

void inicializarPilha(Pilha *pilha){
    pilha->topo = -1;
}

void inserir(Fila *fila, Pessoa pessoa){
    if(fila->fim < MAX){
        fila->pessoas[fila->fim++] = pessoa;
    }
}

Pessoa remover(Fila *fila){
    return fila->pessoas[fila->inicio++];
}

void push(Pilha *pilha, Pessoa pessoa){
    if(pilha->topo < MAX - 1){
        pilha->pessoas[++pilha->topo] = pessoa;
    }
}

Pessoa pop(Pilha *pilha){
    return pilha->pessoas[pilha->topo--];
}

void exibirFila(Fila fila){
    for(int i = fila.inicio; i < fila.fim; i++){
        printf("Nome: %s | Idade: %d\n", fila.pessoas[i].nome, fila.pessoas[i].idade);
    }
}

int main(){
    Fila filaOriginal, filaInvertida;
    Pilha auxiliar;

    inicializarFila(&filaOriginal);
    inicializarFila(&filaInvertida);
    inicializarPilha(&auxiliar);

    Pessoa pessoas[] = {
        {"Carlos", 45}, {"Joana", 62}, {"Lucas", 30}, {"Maria", 75}
    };

    for(int i = 0; i < 4; i++){
        inserir(&filaOriginal, pessoas[i]);
    }

    printf("Fila original:\n");
    exibirFila(filaOriginal);

    while(filaOriginal.inicio < filaOriginal.fim){
        push(&auxiliar, remover(&filaOriginal));
    }

    while(auxiliar.topo >= 0){
        inserir(&filaInvertida, pop(&auxiliar));
    }

    printf("Fila invertida:\n");
    exibirFila(filaInvertida);

    return 0;
}