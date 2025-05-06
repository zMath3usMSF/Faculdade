#include <stdio.h>

int main(){
    int idade, matricula;
    char nome[20];
    float altura;

    printf("Enter your name: \n");
    scanf("%s", nome);

    printf("Enter your age: \n");
    scanf("%d", &idade);

    printf("Enter your height: \n");
    scanf("%f", &altura);

    printf("Enter your registration: \n");
    scanf("%d", &matricula);

    printf("Nome do Aluno: %s - Matricula: %d - ", nome, matricula);
    printf("Idade: %d - Altura: %.2f", idade, altura);
}