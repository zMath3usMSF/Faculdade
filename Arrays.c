#include <stdio.h>

int main(){
    int index;
    char* alunos[3][3] = {{"Jorge", "Português: 4", "Matemática: 7"},
        {"Mario", "Português: 9", "Matemática: 3"},
        {"Ana", "Português: 5", "Matemática: 5"}};
    
    printf("Digite o Número do Aluno(a):\n");
    printf("Jorge = 0\nMario = 1\nAna = 2\n");
    scanf("%d", &index);

    printf("As Notas do Aluno(a): %s são: %s, %s\n", alunos[index][0], alunos[index][1], alunos[index][2]);
}