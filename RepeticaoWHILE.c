#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    long long unsigned int valor = 0;
    int i = 0;
    while(valor != 95){
        valor = rand() % 100000;
        printf("Tentativa %d | Valor %llu\n", i, valor);
        i++;
    }
}