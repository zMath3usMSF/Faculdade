#include <stdio.h>

void saudacao(){
    printf("Olá, mundo!\n");
}

int main(){
    void (*ptr)() = saudacao;

    ptr();

    return 0;
}