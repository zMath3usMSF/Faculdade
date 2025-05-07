#include <stdio.h>

int main(){
    int numero1 = 10, resultado;

    printf("Antes incremento: %d\n", numero1);

    //numero1 = numero1 + 1;
    //numero1 += 1;
    numero1++;
    printf("Após incremento: %d\n", numero1);

    /*
        Pós-incremento:
        resultado = numero1;
        numero1++;
    */
    resultado = numero1++;
    printf("Após pós-incremento - Número 1: %d - Resultado: %d\n", numero1, resultado);
    
    /*
        Pre-incremento:
        numero1++;
        resultado = numero1;
    */
    resultado = ++numero1;
    printf("Após pré-incremento - Número 1: %d - Resultado: %d\n", numero1, resultado);
    
    //numero1 = numero1 - 1;
    //numero1 -= 1;
    numero1--;
    printf("Após decremento: %d\n", numero1);

    /*
        Pós-decremento:
        resultado = numero1;
        numero1--;
    */
    resultado = numero1--;
    printf("Após pós-decremento - Número 1: %d - Resultado: %d\n", numero1, resultado);
   
    /*
        Pre-decremento:
        numero1--;
        resultado = numero1;
    */
    resultado = --numero1;
    printf("Após pré-decremento - Número 1: %d - Resultado: %d\n", numero1, resultado);
   
}