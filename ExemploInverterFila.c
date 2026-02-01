#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
    char nome[30];
    int idade;
} Pessoa;

typedef struct{
    Pessoa dados[MAX];
    int inicio, fim;
} Fila;

typedef struct{
    Pessoa dados[MAX];
    int topo;
} Pilha;

void inicializarFila(Fila *fila){
    fila->inicio = 0;
    fila->fim = 0;
}

void inicializarPilha(Pilha *pilha){
    pilha->topo = -1;
}

void inserir(Fila *fila, Pessoa pessoa){
    if(fila->fim < MAX){
        fila->dados[fila->fim++] = pessoa;
    }
}

Pessoa remover(Fila *fila){
    return fila->dados[fila->inicio++];
}

void push(Pilha *pilha, Pessoa pessoa){
    if(pilha->topo < MAX - 1){
        pilha->dados[++pilha->topo] = pessoa;
    }
}

Pessoa pop(Pilha *pilha){
    return pilha->dados[pilha->topo--];
}

Pessoa peek(Pilha *pilha){
    return pilha->dados[pilha->topo];
}

void exibirFila(Fila fila){
    for(int i = fila.inicio; i < fila.fim; i++){
        printf("Nome: %s | Idade %d\n", fila.dados[i].nome, fila.dados[i].idade);
    }
}

int main(){
    Fila filaOriginal, filaInvertida;
    Pilha auxiliar;

    inicializarFila(&filaOriginal);
    inicializarFila(&filaInvertida);
    inicializarPilha(&auxiliar);

    Pessoa pessoas[] = {{"Carlos", 45}, {"Joana", 62}, {"Lucas", 30}, {"Maria", 75}};

    for(int i = 0; i < 4; i++){
        inserir(&filaOriginal, pessoas[i]);
    }

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
