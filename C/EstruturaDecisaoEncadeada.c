#include <stdio.h>

int main(){
    unsigned int idade;  
    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if(idade >= 60)
    {
        printf("Idoso.");
    }
    else if(idade >= 18)
    {
        printf("Adulto.");
    }
    else if(idade >= 12)
    {
        printf("Adolescente.");
    }
    else
    {
        printf("Criança.");
    }
}