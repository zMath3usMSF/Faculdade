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
};

// Estrutura da Mochila: Array de Estruturas de Itens e Quantidade na Mochila
typedef struct{
    struct Item itens[MAX_ITENS];
    int quantidadeMochila;
}Mochila;
Mochila mochila;

// Função que Exibe o Menu Principal
void exibirMenuPrincipal();

// Função que Adiciona Item
void adicionarItem();
// Função que Remove Item
void removerItem(Mochila* mochila, const char* nome);
// Função que Lista os Itens
void listarItens(const Mochila* mochila);
// Função que limpa o Buff de Entrada
void limparBuffEntrada();
// Função que Busca Item
void buscarItem(Mochila* mochila, const char* nome);

// Função Principal
int main(){
    do{
        exibirMenuPrincipal();
    }while(finalizado == 0);
}

// Função de Exibir o Menu Principal, onde podemos escolher entre Adicionar, Remover ou Listar o Item
// Também podemos sair
void exibirMenuPrincipal(){
    mochila.quantidadeMochila = 0;
    int opcao = 0;
    char nomeItem[30];
    do{
        printf("\n=============================================\n");
        printf("    MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA   ");
        printf("\n=============================================\n");
        printf("Itens na Mochila: %d/%d\n\n", mochila.quantidadeMochila, MAX_ITENS);
        printf("1. Adicionar Item (Loot)\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens na Mochila\n");
        printf("4. Buscar Item\n");
        printf("0. Sair\n");
        printf("------------------------------------------------\n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                adicionarItem();
                break;
            case 2:
                printf("Digite o nome do Item: ");
                nomeItem[30];
                scanf("%s", &nomeItem);
                removerItem(&mochila, nomeItem);
                break;
            case 3:
                listarItens(&mochila);
                break;
            case 4:
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
void adicionarItem(){
    if(mochila.quantidadeMochila == MAX_ITENS){
        printf("Mochila cheia! Remova algum item.");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    printf("Nome do Item: ");
    scanf("%s", &mochila.itens[mochila.quantidadeMochila].nome);
    printf("Tipo do Item (Arma, Municao, Protecao, Cura etc...): ");
    scanf("%s", &mochila.itens[mochila.quantidadeMochila].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila.itens[mochila.quantidadeMochila].quantidadeItem);
    mochila.quantidadeMochila++;
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função de Remover Item, ele pede o nome do Item a ser removido
// É necessário que a Mochila tenha pelo menos algum Item adicionado
void removerItem(Mochila* mochila, const char* nome){
    int i, pos = -1;
    
    for(i = 0; i < mochila->quantidadeMochila; i++){
        if(strcmp(mochila->itens[i].nome, nome) == 0){
            pos = i;
            break;
        }
    }
    
    if(pos == -1){
        printf("Erro: Item \"%s\" nao encontrado na mochila.\n", nome);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    
    for(i = pos; i < mochila->quantidadeMochila - 1; i++){
        strcpy(mochila->itens[i].nome, mochila->itens[i + 1].nome);
        strcpy(mochila->itens[i].tipo, mochila->itens[i + 1].tipo);
        mochila->itens[i].quantidadeItem = mochila->itens[i + 1].quantidadeItem;
    }
    mochila->quantidadeMochila--;
    printf("Item \"%s\" removido com sucesso.\n", nome);
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
    printf("----------------------------------------------------------\n");
    printf("%-15s | %-13s | QUANTIDADE\n", "NOME", "TIPO");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < mochila->quantidadeMochila; i++){
        printf("%-15s | %-13s | %d\n", 
               mochila->itens[i].nome, 
               mochila->itens[i].tipo, 
               mochila->itens[i].quantidadeItem);
    }
    printf("----------------------------------------------------------\n");
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