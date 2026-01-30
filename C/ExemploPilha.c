#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
}Pessoa;

#define MAX 5

typedef struct{
    Pessoa pessoas[MAX];
    int topo;
}Pilha;

void inicializarPilha(Pilha *pilha){
    pilha->topo = -1;
}

int pilhaVazia(Pilha *pilha){
    return pilha->topo == -1;
}

int pilhaCheia(Pilha *pilha){
    return pilha->topo == MAX - 1;
}

void push(Pilha *pilha, Pessoa pessoaInserir){
    if(pilhaCheia(pilha)){
        printf("Pilha cheia. Nao e possivel inserir.\n");
        return;
    }

    pilha->topo++;
    pilha->pessoas[pilha->topo] = pessoaInserir;
}

void pop(Pilha *pilha, Pessoa *pessoaInserir){
    if(pilhaVazia(pilha)){
        printf("Pilha vazia. Nao e possivel remover.\n");
    }

    *pessoaInserir = pilha->pessoas[pilha->topo];
    pilha->topo--;
}

void peek(Pilha *pilha, Pessoa *pessoaVerificar){
    if(pilhaVazia(pilha)){
        printf("Pilha vazia. Nao e possivel espiar.\n");
    }

    *pessoaVerificar = pilha->pessoas[pilha->topo];
}

void mostrarPilha(Pilha *pilha){
    printf("Pilha (topo -> base):\n");
    for(int i = pilha->topo; i >= 0; i--){
        printf("[%s, %d]\n", pilha->pessoas[i].nome, pilha->pessoas[i].idade);
    }

    printf("\n");
}

int main(){
    Pilha pilha;
    inicializarPilha(&pilha);

    Pessoa a = {"Ana", 20};
    Pessoa b = {"Bruno", 35};
    Pessoa c = {"Carlos", 28};

    push(&pilha, a);
    push(&pilha, b);
    push(&pilha, c);

    mostrarPilha(&pilha);

    Pessoa removida;
    pop(&pilha, &removida);
    printf("Removida: %s, %d\n", removida.nome, removida.idade);

    mostrarPilha(&pilha);

    Pessoa topo;
    peek(&pilha, &topo);
    printf("Topo atual: %s, %d\n", topo.nome, topo.idade);

    return 0;
}