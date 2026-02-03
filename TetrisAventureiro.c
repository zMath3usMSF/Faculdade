// Módulos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Contador de ID das Peças
int idTotal = 0;

// Estrutura da Peça
typedef struct{
    char nome;
    int id;
} Peca;

// Número Máximo de Peças na Fila
#define MAX_FILA 5

// Estrutura da Fila
typedef struct{
    Peca pecas[MAX_FILA];
    int inicio;
    int fim;
    int total;
} Fila;

// Número Máximo de Peças na Pilha
#define MAX_PILHA 3

// Estrutura da Pilha
typedef struct{
    Peca pecas[MAX_PILHA];
    int topo;
} Pilha;

// Função que Mostra o Estado Atual da Fila
void mostrarFilaPilha(Fila *fila, Pilha *pilha){
    printf("Fila Atual: ");
    for(int i = 0, idx = fila->inicio; i < fila->total; i++, idx = (idx + 1) % MAX_FILA){
        printf("[%c, %d] ", fila->pecas[idx].nome, fila->pecas[idx].id);
    }
    printf("\n");

    printf("Pilha Atual: ");
    for(int i = pilha->topo; i >= 0; i--){
        printf("[%c, %d] ", pilha->pecas[i].nome, pilha->pecas[i].id);
    }
    printf("\n");

}

// Função que Inicializa a Fila
void inicializarFila(Fila *fila){
    fila->inicio = 0;
    fila->fim = 0;
    fila->total = 0;
}

// Função que Verifica se a Fila está Cheia
int filaCheia(Fila *fila){
    return fila->total == MAX_FILA;
}

// Função que Verifica se a Fila está Vazia
int filaVazia(Fila *fila){
    return fila->total == 0;
}

// Função que Insere uma Peça na Fila
void inserir(Fila *fila, Peca *peca){
    if(filaCheia(fila)){
        printf("Fila cheia. Nao e possivel inserir.\n");
        return;
    }

    fila->pecas[fila->fim] = *peca;
    fila->fim = (fila->fim + 1) % MAX_FILA;
    fila->total++;
}

// Função que Remove uma Peça da Fila
void remover(Fila *fila, Peca *peca){
    if(filaVazia(fila)){
        printf("Fila vazia. Nao e possivel remover.\n");
        return;
    }

    *peca = fila->pecas[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_FILA;
    fila->total--;
}

// Função que Gera uma Peça Aleátoria
Peca gerarPeca(){
    Peca peca;
    int valor = rand() % 3; 
    switch (valor)
    {
        case  0:
            peca.nome = 'I';
            break;
        case  1:
            peca.nome = 'O';
            break;
        case  2:
            peca.nome = 'T';
            break;
        case  3:
            peca.nome = 'L';
            break;
        default:
            break;
    }
    peca.id = idTotal;
    idTotal++;
    return peca;
}

// Função que Adiciona Peças Aleátorias a Fila
void adicionarPecas(Fila *fila){
    for(int i = 0; i < MAX_FILA; i++){
        Peca peca = gerarPeca();
        inserir(fila, &peca);
    }
}

// Função que Insere a Peça na Fila
void inserirPeca(Fila *fila){
    Peca peca = gerarPeca();
    inserir(fila, &peca);
}

// Função que Joga a Peça na Fila
void jogarPeca(Fila *fila, Pilha *pilha, Peca *removida){
    printf("\nJOGANDO PECA...\n");
    remover(fila, removida);
    if(!filaVazia(fila)){
        inserirPeca(fila);
        mostrarFilaPilha(fila, pilha);
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função que Limpa o Buffer de Entrada
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Função que Inicializa a Pilha
void inicializarPilha(Pilha *pilha){
    pilha->topo = -1;
}

// Função que Verifica se a Pilha está Vazia
int pilhaVazia(Pilha *pilha){
    return pilha->topo == -1;
}

// Função que Verifica se a Pilha está Cheia
int pilhaCheia(Pilha *pilha){
    return pilha->topo == MAX_PILHA - 1;
}

// Função que Insere uma Peça na Pilha
void push(Fila *fila, Pilha *pilha, Peca pecaInserir){
    if(pilhaCheia(pilha)){
        printf("Pilha cheia. Nao e possivel inserir.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    pilha->topo++;
    pilha->pecas[pilha->topo] = pecaInserir;
    mostrarFilaPilha(fila, pilha);

    printf("\nPressione ENTER para continuar...");
    getchar();
}


// Função que Remove uma Peça na Pilha
void pop(Fila *fila, Pilha *pilha, Peca *pecaRemover){
    if(pilhaVazia(pilha)){
        printf("Pilha vazia. Nao e possivel remover.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    *pecaRemover = pilha->pecas[pilha->topo];
    pilha->topo--;
    mostrarFilaPilha(fila, pilha);

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função que Reserva uma Peça para a Pilha 
void reservarPeca(Fila *fila, Pilha *pilha){
    printf("\nRESERVANDO PECA...\n");
    Peca removida;
    if(!pilhaCheia(pilha)){
        remover(fila, &removida);
        inserirPeca(fila);
    }
    
    push(fila, pilha, removida);
}

// Função que Usa uma Peça Reservada da Pilha
void usarPeca(Fila *fila, Pilha *pilha){
    printf("\nUSANDO PECA RESERVADA...\n");
    if(pilhaVazia(pilha)){
        printf("OPSSS! Nenhuma peca foi reservada, reserve uma antes.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("[%c, %d]\n\n", pilha->pecas[pilha->topo].nome, pilha->pecas[pilha->topo].id);
    Peca removida;
    pop(fila, pilha, &removida);
}

// Função Principal
int main(){
    srand(time(NULL));

    Fila fila;
    inicializarFila(&fila);
    adicionarPecas(&fila);

    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao = 0;
    do{
        printf("\n===============================================\n");
        printf("                  TETRIS - NOVATO             \n");
        printf("===============================================\n");
        printf("1 - Jogar Peca\n");
        printf("2 - Reservar Peca\n");
        printf("3 - Usar Peca\n");
        printf("0 - Sair\n");
        printf("----------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch(opcao){
            case 1:
                Peca removida;
                jogarPeca(&fila, &pilha, &removida);
                break;
            case 2:
                reservarPeca(&fila, &pilha);
                break;
            case 3:
                usarPeca(&fila, &pilha);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }while(opcao != 0);

}