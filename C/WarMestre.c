#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Número Máximo de Territórios
int maxTerritorios = 5;
// Número Máximo de Missões
int maxMissoes = 1;

// Estrutura do Território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Estrutura das Missões
struct Missao {
    char nome[100];
    char cor[10];
};

// Array Dinâmico de Estruturas de Territórios
struct Territorio* territorios;
// Array Dinâmico de Estrutura de Missões
struct Missao* missoes;

// Variavel que indica se o jogo acabou
int finalizou = 0;

// Variavel que indica o exercito do jogador
int jogadorexercito = 0;

// Protótipos das funções
void limparBuffEntrada();
void iniciarAtaque(struct Territorio* atacante, struct Territorio* defensor);
void adicionarTerritorios();
void exibirMenuMapaMundo();
void solicitarTerritorioDefensor();
void liberarMemoria();
void adicionarMissoes();
void exibirMissoes();
void verificarMissao();
void obterjogadorexercito();
void exibirMenuAcoes();

int main() {
    srand(time(NULL));
    
    adicionarTerritorios();
    adicionarMissoes();
    obterjogadorexercito();
    
    while(1) {
        exibirMenuMapaMundo();
        exibirMissoes();
        verificarMissao();
        exibirMenuAcoes();
        
        if(finalizou == 1) {
            liberarMemoria();
            printf("\nJogo encerrado e memoria liberada. Ate a proxima!\n");
            break;
        }
    }
    
    return 0;
}

// Libera da Memoria as Estruturas Dinamicas dos Territorios e Missoes
void liberarMemoria() {
    free(territorios);
    free(missoes);
}

// Limpa o Buff de Entrada
void limparBuffEntrada() {
    int _char;
    while((_char = getchar()) != '\n' && _char != EOF);
}


// Inicia o Ataque entre os Territorios
void iniciarAtaque(struct Territorio* atacante, struct Territorio* defensor) {
    printf("\n--- INICIANDO ATAQUE ---\n");
    int atacanteResultadoAtq = (rand() % 6) + 1;
    printf("O atacante %s rolou um dado e tirou: %d\n", atacante->nome, atacanteResultadoAtq);
    
    int defensorResultadoAtq = (rand() % 6) + 1;
    printf("O defensor %s rolou um dado e tirou: %d\n", defensor->nome, defensorResultadoAtq);
    
    printf("\n--- RESULTADO ---\n");
    
    if(atacanteResultadoAtq > defensorResultadoAtq) {
        printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");
        
        if(defensor->tropas == 1) {
            // Verifica se completou a missão antes de conquistar
            if(strcmp(defensor->cor, missoes[0].cor) == 0) {
                printf("\n*** PARABENS! Voce completou a sua Missao de Destruir o Exercito %s ***\n", missoes[0].cor);
                finalizou = 1;
            }
            
            printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s\n", defensor->nome, atacante->cor);
            strcpy(defensor->cor, atacante->cor);
        } else {
            defensor->tropas--;
        }
    }
    else if(defensorResultadoAtq > atacanteResultadoAtq) {
        if(atacante->tropas == 1) {
            printf("DERROTA! Voce perdeu, seu territorio %s foi dominado pelo Exercito %s\n", atacante->nome, defensor->cor);
            strcpy(atacante->cor, defensor->cor);
            finalizou = 1;
        } else {
            atacante->tropas--;
        }
    }
    else {
        printf("EMPATE! Ninguem perdeu tropas.\n");
    }
    
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Exibe o Mapa do Mundo, informando todas as informações dos Territórios
void exibirMenuMapaMundo() {
    printf("\n=============================================\n");
    printf("       MAPA DO MUNDO - ESTADO ATUAL          \n");
    printf("=============================================\n");
    
    for(int i = 1; i <= maxTerritorios; i++) {
        printf("%d. %-15s (Exercito %-10s, Tropas: %d)\n", 
               i, 
               territorios[i - 1].nome, 
               territorios[i - 1].cor, 
               territorios[i - 1].tropas);
    }
}

// Exibe o Menu de Ações
void exibirMenuAcoes() {
    int opcao = 0;
    
    printf("\n--- MENU DE ACOES ---\n");
    printf("1 - Atacar\n");
    printf("0 - Sair\n");
    printf("Escolha sua acao: ");
    scanf("%d", &opcao);
    limparBuffEntrada();
    
    switch(opcao) {
        case 1:
            solicitarTerritorioDefensor();
            break;
        case 0:
            finalizou = 1;
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}


// Solicita o Território que o Jogador quer atacar
void solicitarTerritorioDefensor() {
    int territorioDefensor = 0;
    
    printf("\n>>> Seu territorio: %s (Exercito %s) <<<\n", 
           territorios[jogadorexercito - 1].nome,
           territorios[jogadorexercito - 1].cor);
    
    while(1) {
        printf("Escolha o territorio defensor (1 a %d): ", maxTerritorios);
        scanf("%d", &territorioDefensor);
        limparBuffEntrada();
        
        if(territorioDefensor == jogadorexercito) {
            printf("Voce nao pode atacar seu proprio territorio!\n");
        }
        else if(territorioDefensor <= 0 || territorioDefensor > maxTerritorios) {
            printf("Opcao invalida.\n");
        }
        else {
            break;
        }
    }
    
    iniciarAtaque(&territorios[jogadorexercito - 1], &territorios[territorioDefensor - 1]);
}

// Adiciona a Missão do Jogo
void adicionarMissoes() {
    missoes = (struct Missao *) calloc(maxMissoes, sizeof(struct Missao));
    
    int opcaoMissao = rand() % maxTerritorios;
    
    switch(opcaoMissao) {
        case 0:
            strcpy(missoes[0].nome, "Destruir o Exercito Azul");
            strcpy(missoes[0].cor, "Azul");
            break;
        case 1:
            strcpy(missoes[0].nome, "Destruir o Exercito Vermelho");
            strcpy(missoes[0].cor, "Vermelho");
            break;
        case 2:
            strcpy(missoes[0].nome, "Destruir o Exercito Verde");
            strcpy(missoes[0].cor, "Verde");
            break;
        case 3:
            strcpy(missoes[0].nome, "Destruir o Exercito Amarelo");
            strcpy(missoes[0].cor, "Amarelo");
            break;
        case 4:
            strcpy(missoes[0].nome, "Destruir o Exercito Branco");
            strcpy(missoes[0].cor, "Branco");
            break;
        default:
            break;
    }
}

// Define o Exercito do Jogador de forma aleatória
void obterjogadorexercito() {
    while(1) {
        jogadorexercito = (rand() % maxTerritorios) + 1;
        
        if(strcmp(territorios[jogadorexercito - 1].cor, missoes[0].cor) != 0) {
            break;
        }
    }
    
    printf("\n*** Voce controla o Exercito %s no territorio %s ***\n", 
           territorios[jogadorexercito - 1].cor,
           territorios[jogadorexercito - 1].nome);
}

// Exibe a Missão do Jogo
void exibirMissoes() {
    printf("\n--- SUA MISSAO (Exercito %s) ---\n", territorios[jogadorexercito - 1].cor);
    
    for(int i = 0; i < maxMissoes; i++) {
        printf("Missao %d: %s\n", i + 1, missoes[i].nome);
    }
}

// Verifica se a Missão do Jogo foi feita
void verificarMissao() {
    int missaoConcluida = 1;
    
    // Verifica se ainda existe algum território com a cor da missão
    for(int i = 0; i < maxTerritorios; i++) {
        if(strcmp(territorios[i].cor, missoes[0].cor) == 0) {
            missaoConcluida = 0;
            break;
        }
    }
    
    if(missaoConcluida) {
        printf("\n*** PARABENS! Voce completou a sua missao! ***\n");
        finalizou = 1;
    } else {
        printf("Continue a lutar!\n");
    }
}

// Adiciona os Territórios
void adicionarTerritorios() {
    territorios = (struct Territorio *) calloc(maxTerritorios, sizeof(struct Territorio));
    
    strcpy(territorios[0].nome, "America");
    strcpy(territorios[0].cor, "Azul");
    territorios[0].tropas = 5;
    
    strcpy(territorios[1].nome, "Asia");
    strcpy(territorios[1].cor, "Vermelho");
    territorios[1].tropas = 1;
    
    strcpy(territorios[2].nome, "Europa");
    strcpy(territorios[2].cor, "Verde");
    territorios[2].tropas = 1;
    
    strcpy(territorios[3].nome, "Africa");
    strcpy(territorios[3].cor, "Amarelo");
    territorios[3].tropas = 1;
    
    strcpy(territorios[4].nome, "Oceania");
    strcpy(territorios[4].cor, "Branco");
    territorios[4].tropas = 1;
}