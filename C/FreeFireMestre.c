#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Indica se o programa foi finalizado
int finalizado = 0;

// Indica o número maximo de itens na mochila
#define MAX_ITENS 10

// Estrutura do Item: Nome, Tipo e Quantidade
struct Item
{
    char nome[30];
    char tipo[20];
    int quantidadeItem;
    int prioridade;
};

// Estrutura da Mochila: Array de Estruturas de Itens e Quantidade na Mochila
typedef struct{
    struct Item itens[MAX_ITENS];
    int quantidadeMochila;
    int ordenado;
}Mochila;
Mochila mochila;

// Função que Exibe o Menu Principal
void exibirMenuPrincipal();

// Função que Adiciona Item
void adicionarComponente();
// Função que Remove Item
void removerComponente(Mochila* mochila, const char* nome);

void organizarComponentesMenu();

void organizarComponentesNome();

void organizarComponentesTipo();

void organizarComponentesPrioridade();

// Função que Lista os Itens
void listarItens(const Mochila* mochila);
// Função que limpa o Buff de Entrada
void limparBuffEntrada();
// Função que Busca Item
void buscarItem(Mochila* mochila, const char* nome);

int main(){
    mochila.quantidadeMochila = 0;
    mochila.ordenado = 0;
    int opcao = 0;
    char nomeItem[30];
    do{
        printf("\n=============================================\n");
        printf("    PLANO DE FUGA - CODIGO DA ILHA (NIVEL MESTRE)   ");
        printf("\n=============================================\n");
        printf("Itens na Mochila: %d/%d\n", mochila.quantidadeMochila, MAX_ITENS);
        printf("Status da Ordenacao por Nome: %s\n", mochila.ordenado == 0 ? "NAO ORDENADO" : "ORDENADO");
        printf("1. Adicionar Componente\n");
        printf("2. Descartar Componente\n");
        printf("3. Listar Componentes (Inventario)\n");
        printf("4. Organizar Mochila (Ordenar Componentes)\n");
        printf("5. Busca Binaria por Componente-Chave (por nome)\n");
        printf("0. ATIVAR TORRE DE FUGA (Sair)\n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                adicionarComponente();
                break;
            case 2:
                printf("Digite o nome do Item: ");
                nomeItem[30];
                scanf("%s", &nomeItem);
                removerComponente(&mochila, nomeItem);
                break;
            case 3:
                listarItens(&mochila);
                break;
            case 4:
                organizarComponentesMenu();
                break;
            case 5:
                printf("--- Buscar Item na Mochila ---\n");
                printf("Digite o nome do item que deseja buscar: ");
                nomeItem[30];
                scanf("%s", &nomeItem);
                buscarItem(&mochila, nomeItem);
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


// Função de Adicionar Item, fornecendo o seu Nome, Tipo e Quantidade
// Não é possível adicionar Itens quando a Mochila atinge seu limite (10)
void adicionarComponente(){
    if(mochila.quantidadeMochila == MAX_ITENS){
        printf("Mochila cheia! Remova algum componente.");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    printf("--- Coletando Novo Componente ---\n");
    printf("Nome: ");
    scanf("%s", &mochila.itens[mochila.quantidadeMochila].nome);
    printf("Tipo (Estrutural, Eletronico, Energia): ");
    scanf("%s", &mochila.itens[mochila.quantidadeMochila].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila.itens[mochila.quantidadeMochila].quantidadeItem);
    printf("Prioridade (1-5): ");
    scanf("%d", &mochila.itens[mochila.quantidadeMochila].prioridade);
    mochila.quantidadeMochila++;
    
    printf("Componente '%s' adicionado!\n", mochila.itens[mochila.quantidadeMochila-1].nome);
    listarItens(&mochila);
}

void organizarComponentesMenu(){
    int opcao = 0;
    if(mochila.quantidadeMochila < 2){
        printf("A mochila nao precisa ser organizada!\n");
        return;
    }
    do{
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
                organizarComponentesNome();
                break;
            case 2:
                organizarComponentesTipo();
                break;
            case 3:
                organizarComponentesPrioridade();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
        limparBuffEntrada();
    }while(opcao != 0);    
}

void organizarComponentesNome(){
    for(int i = 0; i < MAX_ITENS; i++){
        int indiceMenor = i;

        for(int j = i + 1; j < MAX_ITENS; j++){
            if(&mochila.itens[j].nome[0] < &mochila.itens[indiceMenor].nome[0]){
                indiceMenor = j;
            }
        }

        if(indiceMenor != i){
            struct Item *a = &mochila.itens[i];
            struct Item *b = &mochila.itens[indiceMenor];
            struct Item temp = *a;
            *a = *b;
            *b = temp;
        }
    }
}

void organizarComponentesTipo(){

}

void organizarComponentesPrioridade(){
    
}

// Função de Remover Item, ele pede o nome do Item a ser removido
// É necessário que a Mochila tenha pelo menos algum Item adicionado
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
        mochila->itens[i].quantidadeItem = mochila->itens[i + 1].quantidadeItem;
        mochila->itens[i].prioridade = mochila->itens[i + 1].prioridade;
    }
    mochila->quantidadeMochila--;
    printf("Componente \"%s\" removido com sucesso.\n", nome);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função que Lista todos os Itens da Mochila
// É necessário que a Mochila tenha pelo menos algum Item adicionado
void listarItens(const Mochila *mochila){
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
               mochila->itens[i].quantidadeItem,
               mochila->itens[i].prioridade);
    }
    printf("------------------------------------------------------------------------\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função de Buscar Item, ele pede o nome do Item a ser buscado
// É necessário que a Mochila tenha pelo menos algum Item adicionado
void buscarItem(Mochila* mochila, const char* nome){
    int itemIndice = -1;
    if(mochila->quantidadeMochila == 0){
        printf("A mochila esta vazia!\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    for(int i = 0; i < mochila->quantidadeMochila; i++){
        if(strcmp(mochila->itens[i].nome, nome) == 0){
            itemIndice = i;
            break;
        }
    }
    if(itemIndice != -1){
        printf("\n--- Item Encontrado! ---\n");
        printf("Nome: %s\n", mochila->itens[itemIndice].nome);
        printf("Tipo: %s\n", mochila->itens[itemIndice].tipo);
        printf("Quantidade: %d\n", mochila->itens[itemIndice].quantidadeItem);
        printf("------------------------\n");
    }else{
        printf("Resultado: Item '%s' NAO foi encontrado na mochila.\n", nome);
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função que limpa o Buff de Entrada
void limparBuffEntrada() {
    int _char;
    while((_char = getchar()) != '\n' && _char != EOF);
}