#include <stdio.h>

int main(){
    int idade;

    printf("Verificador de Idade\n");
    printf("Digite a sua Idade: ");
    scanf("%d", &idade);
    
    if(idade >= 18)
    {
        printf("Você é maior de Idade");
    }
    else
    {
        printf("Você é menor de Idade");
    }
}