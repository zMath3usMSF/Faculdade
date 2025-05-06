#include <stdio.h>

int main(){
    char letra = 'z';
    char nome[20] = "Matheus";
    int idade = 19;
    float altura = 1.79;
    double peso = 0.0;

    printf ("The Letter is: %c\n", letra);
    printf("The Name is: %s\n", nome);
    printf("The Age is: %d\n", idade);
    printf("The Height is: %.2f\n", altura);
    printf("The Weight is: %.2f\n", peso);
    return 0;
}