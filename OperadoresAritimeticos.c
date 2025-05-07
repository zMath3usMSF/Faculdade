#include <stdio.h>

int main(){
    int numero1, numero2;
    int soma, subtracao, multiplicacao, divisao;

    printf("Entre com o Número 1: ");
    scanf("%d", &numero1);

    printf("Entre com o Número 2: ");
    scanf("%d", &numero2);

    //Operação Soma
    soma = numero1 + numero2;

    //Operação Subtração
    subtracao = numero1 - numero2;

    //Operação Multiplicação
    multiplicacao = numero1 * numero2;

    //Operação Divisão
    divisao = numero1 / numero2;

    printf("A Soma é: %d\n", soma);
    printf("A Subtração é: %d\n", subtracao);
    printf("A Multiplicação é: %d\n", multiplicacao);
    printf("A Divisão é: %d\n", divisao);
}