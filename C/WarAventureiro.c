//Incluir a Biblioteca StdIO, StdLib e StrIng
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Número Máximo de Territórios
int maxTerritorios = 0;

//Número de Territórios Dominados
int territoriosDominados = 0;

//Estrutura do Território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

//Função de Limpar Buff de Entrada para evitar possíveis problemas com o scanf
void limparBuffEntrada(){
    int _char;
    while((_char = getchar()) != '\n' && _char != EOF);
}


//Função de Iniciar o Ataque entre os Territórios
void Atacar(struct Territorio* atacante, struct Territorio* defensor){
    int atacanteResultadoAtq = (rand() % 6) + 1;
    printf("O atacante %s rolou um dado e tirou: %d\n", atacante->nome, atacanteResultadoAtq);

    int defensorResultadoAtq = (rand() % 6) + 1;
    printf("O defensor %s rolou um dado e tirou: %d\n", defensor->nome, defensorResultadoAtq);

    //Verifica se o Resultado do Ataque do Território Atacante é Maior do que o do Território Defensor
    if(atacanteResultadoAtq > defensorResultadoAtq){
        printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");

        //Verifica se o Defensor tem apenas 1 tropa, se tiver, o Atacante dominou o Território
        //Senão, apenas remove 1 Tropa do Defensor
        if(defensor->tropas == 1){
            printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s\n", defensor->nome, atacante->cor);
            strcpy(defensor->cor, atacante->cor);
            territoriosDominados++;
        }else{
            defensor->tropas--;
        }
    } 

    //Verifica se o Resultado do Ataque do Território Defensor é Maior do que o do Território Atacante
    else if(defensorResultadoAtq > atacanteResultadoAtq){
        printf("VITORIA DA DEFESA! O atacante perdeu 1 tropa.\n");

        //Verifica se o Atacante tem apenas 1 tropa, se tiver, o Defensor dominou o Território
        //Senão, apenas remove 1 Tropa do Atacante
        if(atacante->tropas == 1){
            printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s\n", atacante->nome, defensor->cor);
            strcpy(atacante->cor, defensor->cor);
            territoriosDominados++;
        }else{
            atacante->tropas--;
        }
    } 
    
    //Caso não seja nenhum dos casos, é porque os resultados dos ataques são iguais
    else{
        printf("EMPATE! Ninguem perdeu tropas.\n");
    }
}

int main(){
    srand(time(NULL));

    //Exibir Mensagme de Cadastro Inicial
    printf("===============================================\n");
    printf("    WAR ESTRUTURADO - CADASTRO INICIAL  \n");
    printf("===============================================\n");

    //Solicitar o Número Máximo de Territórios a serem Cadastrados
    while(1){
        printf("Diga o Numero Maximo de Territorios: ");
        scanf("%d", &maxTerritorios);
        limparBuffEntrada();
        if(maxTerritorios <= 1){
            printf("O jogo precisa de no minimo 2 territorios para iniciar!\n");
        }
        else{
            break;
        }
    }

    //Array Dinâmico de Estruturas de Territórios
    struct Territorio* territorios = (struct Territorio *) calloc(maxTerritorios, sizeof(struct Territorio));

    //Verifica antes se o Usuário ja atingiu o Número Maximo de Territórios, se sim, exibe uma mensagem de erro, se nao, continua o código de Cadastro 
    for(int i = 1; i <= maxTerritorios; i++){
        printf("--- Cadastrando Territorio %d ---\n", i);

        //código de Cadastro
        //Pede para o Usuário Digitar o Nome do Território
        printf("Nome do Territorio: ");
        //Escaneia o valor inserido pelo Usuário e armazena na Variavel do Nome do Território
        fgets(territorios[i - 1].nome, 30, stdin);

        //Pede para o Usuário Digitar a Cor do Território
        printf("Cor do Territorio: ");
        //Escaneia o valor inserido pelo Usuário e armazena na Variavel da Cor do Território
        fgets(territorios[i - 1].cor, 10, stdin);

        //Remove as quebras de linhas nas variaveis de Nome do Território e Cor do Território
        territorios[i - 1].nome[strcspn(territorios[i - 1].nome, "\n")] = '\0';
        territorios[i - 1].cor[strcspn(territorios[i - 1].cor, "\n")] = '\0';

        //Pede para o Usuário Digitar o Número de Tropas do Territorio
        printf("Numero de Tropas: ");
        //Escaneia o valor inserido pelo Usuário e armazena na Variavel de Número de Tropas do Território
        scanf("%d", &territorios[i - 1].tropas);

        //Executa a Função de Limpar Buff de Entrada
        limparBuffEntrada();
    }

    //Variavel que contem a Opção Selecionada
    int opcao;

    //Indice de Territorio Atacante
    int territorioAtacante = 0;
    //Indice do Territorio Defensor
    int territorioDefensor = 0;
    do {
        //Exibir Estado Atual dos Territórios
        printf("\n=============================================\n");
        printf("    MAPA DO MUNDO - ESTADO ATUAL    \n");
        printf("=============================================\n");
        for(int i = 1; i <= maxTerritorios; i++){
            printf("%d. %s (Exercito %s, Tropas: %d)\n", i, territorios[i - 1].nome, territorios[i - 1].cor, territorios[i - 1].tropas);
        }

        //Antes de começar a rodada, verifica se todos os territórios já foram dominados
        //Se foram, encerra o jogo
        if(territoriosDominados == maxTerritorios - 1){
            printf("FIM DE JOGO! O Exercito %s venceu!\n", territorios[0].cor);
            printf("Jogo encerrado e memoria liberada. Ate a proxima!\n");

            //Liberar o Array de Territórios da Memória
            free(territorios);

            //Encerra o Programa com Saída 0
            return 0;
        }

        //Exibe Informações da Fase de Ataque
        printf("\n--- FASE DE ATAQUE ---\n");

        //Solicita o Território Atacante
        while(1) {
            printf("Escolha o territorio atacante (1 a %d, ou 0 para sair): ", maxTerritorios);
            scanf("%d", &territorioAtacante);

            //Verifica se o Território Atacante é Válido ou é Opção para Sair
            if(territorioAtacante < 0 || territorioAtacante > maxTerritorios) printf("Opcao invalida.\n");
            else{
                break;
            }
            
            //Executa a Função de Limpar Buff de Entrada
            limparBuffEntrada();
        }

        //Transfare o Valor do Territorio Atacante também como Opção
        opcao = territorioAtacante;

        //Executa a Função de Limpar Buff de Entrada
        limparBuffEntrada();

        //Inicia um Switch com base na Opção inserada pelo Usuário e tomar as decisoes correspondentes
        switch(opcao){
            //Verifica se a Opção escolhida foi 0, se sim, entrará no código de Saída do Sistema      
            case 0:
                //Exibe que está Saindo do Sistema
                printf("Jogo encerrado e memoria liberada. Ate a proxima!\n");
                //Encerra e volta para o Menu Principal
                break;
            //Caso o Valor da Opção não seja 0, continua o jogo
            default:
                //Solicita o Território Defensor, Verifica se o Território Defensor é Válido e é diferente do Território Atacante
                while(1) {
                    printf("Escolha o territorio defensor (1 a %d): ", maxTerritorios);
                    scanf("%d", &territorioDefensor);

                    if(territorioDefensor == territorioAtacante) printf("Este territorio ja foi escolhido como atacante, use outro.\n");
                    else if(territorioDefensor <= 0 || territorioDefensor > maxTerritorios) printf("Opcao invalida.\n");
                    else{
                        break;
                    }

                    //Executa a Função de Limpar Buff de Entrada
                    limparBuffEntrada();
                }

                //Inicia o Ataque entre os Territórios
                Atacar(&territorios[territorioAtacante - 1], &territorios[territorioDefensor - 1]);

                //Reseta os Valores dos Territórios de Ataque e Defesa
                territorioAtacante = 0; 
                territorioDefensor = 0;
        }
    } while (opcao != 0);

    free(territorios);

    //Encerra o Programa com Saída 0
    return 0;
}