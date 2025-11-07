#include <stdio.h>

int main()
{
    unsigned int idadeMinima = 18, idadeMaxima = 26;
    unsigned int idade;

    printf("Digite sua idade: ");
    scanf("%u", &idade);
    if(idade >= idadeMinima && idade <= idadeMaxima)
    {
        printf("Você tem a idade permitida.");
    }
    else
    {
        if((idade < idadeMinima) || !idade)
        {
            printf("Você é novo demais!");
        }
        else
        {
            printf("Você é velho demais!");
        }
    }
}