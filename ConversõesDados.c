#include <stdio.h>

int main(){
    int a = 10;
    float b = 3.5;
    float soma = a + b; // 'a' é convertido implicítamente para float.
    printf("Resultado da Conversão Implicíta entre (int)%d + (float)%.2f = (float)%0.2f\n(Não houve perda de dados)\n", a, b, soma);

    int c = 10;
    int d = 3;
    float quociente = c / d; // 'a' é convertido implicítamente para float.
    printf("Resultado da Conversão Implicíta entre (int)%d / (int)%d = (float)%.2f\n(Houve perda de dados)\n", c, d, quociente);

    quociente = (float) c / d; // 'a' é convertido explicítamente para float.
    printf("Resultado da Conversão Explicíta entre (float)((int)%d / (int)%d = (float)%.2f)\n(Não houve perda de dados)\n", c, d, quociente);
}