#include <stdio.h>

int main(){
    char letra;
    char nome[20];
    int idade;
    float altura;

    printf("Digite sua letra: ");
    scanf("%c", &letra);
    printf("Sua letra é: %c\n", letra);
    
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Seu nome é: %s\n", nome);
        
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Sua idade é: %d\n", idade);
        
    printf("Digite sua altura: ");
    scanf("%f", &altura);
    printf("Sua altura é: %.2f\n", altura);
}