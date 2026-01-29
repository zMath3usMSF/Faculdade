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
#define MAX 5

// Estrutura da Fila
typedef struct{
    Peca pecas[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// Função que Mostra o Estado Atual da Fila
void mostrarFila(Fila *fila){
    printf("Fila Atual: ");

    for(int i = 0, idx = fila->inicio; i < fila->total; i++, idx = (idx + 1) % MAX){
        printf("[%c, %d] ", fila->pecas[idx].nome, fila->pecas[idx].id);
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
    return fila->total == MAX;
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
    fila->fim = (fila->fim + 1) % MAX;
    fila->total++;
    mostrarFila(fila);
}

// Função que Remove uma Peça da Fila
void remover(Fila *fila, Peca *peca){
    if(filaVazia(fila)){
        printf("Fila vazia. Nao e possivel remover.\n");
        return;
    }

    *peca = fila->pecas[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->total--;
    mostrarFila(fila);
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
    for(int i = 0; i < MAX; i++){
        Peca peca = gerarPeca();
        inserir(fila, &peca);
        mostrarFila(fila);
    }
}

// Função que Joga a Peça na Fila
void jogarPeca(Fila *fila){
    printf("\nJOGANDO PECA...\n");
    Peca removida;
    remover(fila, &removida);

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função que Insere a Peça na Fila
void inserirPeca(Fila *fila){
    printf("\nINSERINDO PECA...\n");
    Peca peca = gerarPeca();
    inserir(fila, &peca);

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função que Limpa o Buffer de Entrada
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Função Principal
int main(){
    srand(time(NULL));

    Fila fila;
    inicializarFila(&fila);

    adicionarPecas(&fila);

    int opcao = 0;
    do{
        printf("\n===============================================\n");
        printf("                  TETRIS - NOVATO             \n");
        printf("===============================================\n");
        printf("1 - Jogar Peca\n");
        printf("2 - Inserir Peca\n");
        printf("0 - Sair\n");
        printf("----------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch(opcao){
            case 1:
                jogarPeca(&fila);
                break;
            case 2:
                inserirPeca(&fila);
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