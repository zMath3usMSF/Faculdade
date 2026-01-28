#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Indica se o programa foi finalizado
int finalizado = 0;

clock_t inicio, fim;
double tempo;

// Indica o número maximo de itens na mochila
#define MAX_ITENS 10

// Estrutura do Componente: Nome, Tipo e Quantidade
struct Componente
{
    char nome[30];
    char tipo[20];
    int quantidadeComponente;
    int prioridade;
};

// Estrutura da Mochila: Array de Estruturas de Itens e Quantidade na Mochila
typedef struct{
    struct Componente itens[MAX_ITENS];
    int quantidadeMochila;
    int ordenado;
}Mochila;
Mochila mochila;

// Função que Exibe o Menu Principal
void exibirMenuPrincipal();

// Função que Adiciona Componente
void adicionarComponente();
// Função que Remove Componente
void removerComponente(Mochila* mochila, const char* nome);

void organizarComponentesMenu();

void bubbleSortNome();

void insertionSortTipo();

void selectionSortPrioridade();

// Função que Lista os Itens
void listarComponentes(const Mochila* mochila);
// Função que limpa o Buff de Entrada
void limparBuffEntrada();
// Função que Busca Componente
void buscarComponente(Mochila* mochila);

int main(){
    mochila.quantidadeMochila = 0;
    mochila.ordenado = 0;
    int opcao = 0;
    char nomeComponente[30];
    do{
        printf("\n=============================================\n");
        printf("    PLANO DE FUGA - CODIGO DA ILHA (NIVEL MESTRE)   ");
        printf("\n=============================================\n");
        printf("Itens na Mochila: %d/%d\n", mochila.quantidadeMochila, MAX_ITENS);
        printf("Status da Ordenacao por Nome: %s\n\n", mochila.ordenado == 0 ? "NAO ORDENADO" : "ORDENADO");
        printf("1. Adicionar Componente\n");
        printf("2. Descartar Componente\n");
        printf("3. Listar Componentes (Inventario)\n");
        printf("4. Organizar Mochila (Ordenar Componentes)\n");
        printf("5. Busca Binaria por Componente-Chave (por nome)\n");
        printf("0. ATIVAR TORRE DE FUGA (Sair)\n");
        printf("\nEscolha uma Opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                adicionarComponente();
                break;
            case 2:
                printf("Digite o nome do Componente: ");
                nomeComponente[30];
                scanf("%s", &nomeComponente);
                removerComponente(&mochila, nomeComponente);
                break;
            case 3:
                listarComponentes(&mochila);
                break;
            case 4:
                organizarComponentesMenu();
                break;
            case 5:
                buscarComponente(&mochila);
                break;
            case 0:
                finalizado = 1;
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
        limparBuffEntrada();
    }while(opcao != 0);
}


// Função de Adicionar Componente, fornecendo o seu Nome, Tipo e Quantidade
// Não é possível adicionar Itens quando a Mochila atinge seu limite (10)
void adicionarComponente(){
    if(mochila.quantidadeMochila == MAX_ITENS){
        printf("Mochila cheia! Remova algum componente.");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    printf("\n--- Coletando Novo Componente ---\n");
    printf("Nome: ");
    scanf("%s", &mochila.itens[mochila.quantidadeMochila].nome);
    printf("Tipo (Estrutural, Eletronico, Energia): ");
    scanf("%s", &mochila.itens[mochila.quantidadeMochila].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila.itens[mochila.quantidadeMochila].quantidadeComponente);
    printf("Prioridade (1-5): ");
    scanf("%d", &mochila.itens[mochila.quantidadeMochila].prioridade);
    mochila.quantidadeMochila++;
    mochila.ordenado = 0;
    
    printf("Componente '%s' adicionado!\n", mochila.itens[mochila.quantidadeMochila-1].nome);
    listarComponentes(&mochila);
}

void organizarComponentesMenu(){
    int opcao = 0;
    if(mochila.quantidadeMochila < 2){
        printf("\nA mochila deve ter 2 ou mais componentes!\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    printf("\n--- Estrategia de Organizacao ---\n");
    printf("1. Por Nome (Ordem Alfabetica)\n");
    printf("2. Por Tipo\n");
    printf("3. Por Prioridade de Montagem\n");
    printf("0. Cancelar\n");
    printf("Escolha o criterio: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            bubbleSortNome();
            break;
        case 2:
            insertionSortTipo();
            break;
        case 3:
            selectionSortPrioridade();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}

void bubbleSortNome(){
    inicio = clock();
    for(int i = 0; i < mochila.quantidadeMochila; i++){
        for(int j = 0; j < mochila.quantidadeMochila - i - 1; j++){
            if(strcmp(mochila.itens[j].nome, mochila.itens[j + 1].nome) > 0){
                struct Componente* a = &mochila.itens[j];
                struct Componente* b = &mochila.itens[j + 1];
                struct Componente temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    mochila.ordenado = 1;
    printf("Mochila organizada por NOME");
    printf("Tempo de CPU da Ordenacao de Nomes usando Bubble Sort: %f segundos\n", tempo);
    listarComponentes(&mochila);
}

void insertionSortTipo(){
    for(int i = 1; i < mochila.quantidadeMochila; i++){
        struct Componente chave = mochila.itens[i];
        int j = i - 1;

        while(j >= 0 && strcmp(mochila.itens[j].tipo, chave.tipo) > 0){
            mochila.itens[j + 1] = mochila.itens[j];
            j--;
        }
    
        mochila.itens[j + 1] = chave;
    }
    mochila.ordenado = 1;
    printf("Mochila organizada por TIPO");
    listarComponentes(&mochila);
}

void selectionSortPrioridade(){
    for(int i = 0; i < mochila.quantidadeMochila - 1; i++){
        int indiceMenor = i;

        for(int j = i + 1; j < mochila.quantidadeMochila; j++){
            if(mochila.itens[j].prioridade < mochila.itens[indiceMenor].prioridade){
                indiceMenor = j;
            }
        }

        if(indiceMenor != i){
            struct Componente* a = &mochila.itens[i];
            struct Componente* b = &mochila.itens[indiceMenor];
            struct Componente temp = *a;
            *a = *b;
            *b = temp;
        }
    }
    mochila.ordenado = 1;
    printf("Mochila organizada por PRIORIDADE");
    listarComponentes(&mochila);
}

// Função de Remover Componente, ele pede o nome do Componente a ser removido
// É necessário que a Mochila tenha pelo menos algum Componente adicionado
void removerComponente(Mochila* mochila, const char* nome){
    int i, pos = -1;
    
    for(i = 0; i < mochila->quantidadeMochila; i++){
        if(strcmp(mochila->itens[i].nome, nome) == 0){
            pos = i;
            break;
        }
    }
    
    if(pos == -1){
        printf("Erro: Componente \"%s\" nao encontrado na mochila.\n", nome);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    
    for(i = pos; i < mochila->quantidadeMochila - 1; i++){
        strcpy(mochila->itens[i].nome, mochila->itens[i + 1].nome);
        strcpy(mochila->itens[i].tipo, mochila->itens[i + 1].tipo);
        mochila->itens[i].quantidadeComponente = mochila->itens[i + 1].quantidadeComponente;
        mochila->itens[i].prioridade = mochila->itens[i + 1].prioridade;
    }
    mochila->quantidadeMochila--;
    printf("Componente \"%s\" removido com sucesso.\n", nome);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função que Lista todos os Itens da Mochila
// É necessário que a Mochila tenha pelo menos algum Componente adicionado
void listarComponentes(const Mochila *mochila){
    if(mochila->quantidadeMochila == 0){
        printf("A mochila esta vazia.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    printf("\n--- ITENS NA MOCHILA (%d/%d) ---\n", mochila->quantidadeMochila, MAX_ITENS);
    printf("------------------------------------------------------------------------\n");
    printf("%-15s | %-13s | %-15s | PRIORIDADE\n", "NOME", "TIPO", "QUANTIDADE");
    printf("------------------------------------------------------------------------\n");
    for(int i = 0; i < mochila->quantidadeMochila; i++){
        printf("%-15s | %-13s | %-15d | %d\n", 
               mochila->itens[i].nome, 
               mochila->itens[i].tipo, 
               mochila->itens[i].quantidadeComponente,
               mochila->itens[i].prioridade);
    }
    printf("------------------------------------------------------------------------\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função de Buscar Componente, ele pede o nome do Componente a ser buscado
// É necessário que a Mochila tenha pelo menos algum Componente adicionado
void buscarComponente(Mochila* mochila){
    if(mochila->ordenado == 0 && mochila->itens != 0){
        printf("ALERTA: A busca binaria requer que a mochila esteja ordenada por NOME.\n");
        printf("Use a Opcao 4 para organizar a mochila primeiro.\n");

        printf("\nPressione ENTER para continuar...");
        getchar();
    }else{
        printf("--- Busca Binaria por Componente-Chave ---\n");
        printf("Digite o Nome do Componente que deseja buscar: ");
        char nome[30];
        scanf("%s", &nome);

        int ComponenteIndice = -1;
        if(mochila->quantidadeMochila == 0){
            printf("A mochila esta vazia!\n");
            printf("\nPressione ENTER para continuar...");
            getchar();
            return;
        }

        int inicio = 0;
        int fim = mochila->quantidadeMochila - 1;
        int encontrado = 0;
        while(inicio <= fim){
            int meio = inicio + (fim - inicio) / 2;

            if(strcmp(mochila->itens[meio].nome, nome) == 0){
                printf("\n--- Componente-Chave Encontrado! ---\n");
                printf("Nome: %s, Tipo: %s, Qtd: %d, Prio: %d",
                        mochila->itens[meio].nome,
                        mochila->itens[meio].tipo,
                        mochila->itens[meio].quantidadeComponente,
                        mochila->itens[meio].prioridade
                    );
                encontrado = 1;
                break;
            }
            else if(strcmp(mochila->itens[meio].nome, nome) < 0){
                inicio = meio + 1;
            }
            else{
                fim = meio - 1;
            }
        }
        if(encontrado == 0){
            printf("Componente-Chave '%s' NAO foi encontrado na mochila.\n", nome);
        }

        printf("\nPressione ENTER para continuar...");
        getchar();
    }
}

// Função que limpa o Buff de Entrada
void limparBuffEntrada() {
    int _char;
    while((_char = getchar()) != '\n' && _char != EOF);
}