//Incluir a Biblioteca StdIO, StdLib e StrIng
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Número Máximo de Territórios
#define MAX_TERRITORIOS 5

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

int main(){
    //Array de Estruturas de Territórios
    struct Territorio territorios[MAX_TERRITORIOS];
    //Variavel que contem o Número Total de Territórios Cadastrados 
    int totalTerritorios = 0;
    //Variavel que contem a Opção Selecionada
    int opcao;

    do {
        //Exibe Informações de Comandos de Cadastro de Territórios
        printf("=============================================\n");
        printf("    War - Sistema de Cadastro de Territorios\n");
        printf("1 - Cadastrar novo Territorio\n");
        printf("2 - Listar todos os Territorios\n");
        printf("0 - Sair\n");
        printf("----------------------------------------------\n");
        printf("Escolha uma opcao: ");

        //Escaneia o valor inserido pelo Usuário e armazena na Variavel Opção 
        scanf("%d", &opcao);
        //Executa a Função de Limpar Buff de Entrada
        limparBuffEntrada();

        //Inicia um Switch com base na Opção inserada pelo Usuário e tomar as decisoes correspondentes
        switch(opcao){
            //Verifica se a Opção escolhida foi 1, se sim, entrará no código de Cadastro de Territórios
            case 1:
                //Verifica antes se o Usuário ja atingiu o Número Maximo de Territórios, se sim, exibe uma mensagem de erro, se nao, continua o código de Cadastro 
                if(totalTerritorios < MAX_TERRITORIOS)
                {
                    //código de Cadastro
                    //Pede para o Usuário Digitar o Nome do Território
                    printf("Digite o Nome do Territorio: ");
                    //Escaneia o valor inserido pelo Usuário e armazena na Variavel do Nome do Território
                    fgets(territorios[totalTerritorios].nome, 30, stdin);

                    //Pede para o Usuário Digitar a Cor do Território
                    printf("Digite a Cor do Territorio: ");
                    //Escaneia o valor inserido pelo Usuário e armazena na Variavel da Cor do Território
                    fgets(territorios[totalTerritorios].cor, 10, stdin);

                    //Remove as quebras de linhas nas variaveis de Nome do Território e Cor do Território
                    territorios[totalTerritorios].nome[strcspn(territorios[totalTerritorios].nome, "\n")] = '\0';
                    territorios[totalTerritorios].cor[strcspn(territorios[totalTerritorios].cor, "\n")] = '\0';

                    //Pede para o Usuário Digitar o Número de Tropas do Territorio
                    printf("Digite o Numero de Tropas: ");
                    //Escaneia o valor inserido pelo Usuário e armazena na Variavel de Número de Tropas do Território
                    scanf("%d", &territorios[totalTerritorios].tropas);

                    //Atualiza o Valor Total de Território Cadastrados
                    totalTerritorios++;

                    //Exibe para o Usuário que o Território foi Cadastrado com Sucesso
                    printf("\nTerritorio Cadastrado com Sucesso!\n");
                }else{
                    //Exibe para o Usuário que o Limite de Territórios foi atingido
                    printf("Limite de Territorios atingido! Nao foi possivel adicionar mais territorios.\n");
                }

                //Depois de Cadastrar o Território, Exibe para o Usuário pressionar ENTER para continuar
                printf("\nPressione ENTER para continuar...");
                //Executa a função de Obter Caractere do Usuário
                getchar();
                //Encerra o Cadastro de Território e volta para o Menu Principal
                break;

            //Verifica se a Opção escolhida foi 2, se sim, entrará no código de Listagem de Territórios    
            case 2:
                //Exibe o Cabeçalho de Territórios Cadastrados
                printf("--- Lista de Territorios Cadastrados ---\n\n");

                //Verifica se o Valor Total de Territórios Cadastrados é 0, se for Exibe para o Usuário que nenhum Território foi Cadastrado ainda
                if(totalTerritorios == 0){
                    printf("Nenhum Territorio cadastrado ainda.\n");
                }
                //Se houver Territórios Cadastrados, ele irá exibir as suas informações
                else{
                    //Inicia um for para percorrer por todos os Territórios Cadastrados com base no Valor Total de Territórios Cadastrados
                    for(int i = 0; i < totalTerritorios; i++){
                        //Exibe as Informações de Nome, Cor e Número de Tropas do Território
                        printf("----------------------------------------------\n");
                        printf("TERRITORIO %d\n", i + 1);
                        printf("Nome: %s\n", territorios[i].nome);
                        printf("Cor: %s\n", territorios[i].cor);
                        printf("Tropas: %d\n", territorios[i].tropas);
                    }
                    printf("----------------------------------------------\n");
                }

                //Depois de Listar todos os Territórios, Exibe para o Usuário pressionar ENTER para continuar
                printf("\nPressione ENTER para continuar...");
                //Executa a função de Obter Caractere do Usuário
                getchar();
                //Encerra a Listagem de Territórios e volta para o Menu Principal
                break;
            //Verifica se a Opção escolhida foi 0, se sim, entrará no código de Saída do Sistema      
            case 0:
                //Exibe que está Saindo do Sistema
                printf("Saindo do Sistema...\n");
                //Encerra e volta para o Menu Principal
                break;
            //Caso o Valor da Opção não seja nenhum dos anteriores, ela é inválida
            default:
                //Exibe que a Opção é Inválida
                printf("\nOpcao invalida! Tente novamente.\n");
                //Exibe para o Usuário pressionar ENTER para continuar
                printf("\nPressione ENTER para continuar...");
                //Executa a função de Obter Caractere do Usuário
                getchar();
                //Encerra e volta para o Menu Principal
                break;
        }
    } while (opcao != 0);

    //Encerra o Programa com Saída 0
    return 0;
}