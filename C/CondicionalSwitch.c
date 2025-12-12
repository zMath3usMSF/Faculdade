#include <stdio.h>

int main(){
    int opcao;
    float saldo = 1000.00;

    printf("Menu de Opções:\n");
    printf("1. Verificar saldo\n");
    printf("2. Fazer depósito\n");
    printf("3. Fazer saque\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("O seu saldo é de R$ %.2f.\n", saldo);
        break;
    case 2:
        printf("Digite o banco, agência e conta que deseja depositar.");
        break;
    case 3:
        printf("Digite o banco, agência e conta que deseja sacar.");
        break;
    default:
        printf("Opção inválida.");
        break;
    }
}