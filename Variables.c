#include <stdio.h>

int main(){
    char letter = 'z';
    char name[20] = "Matheus";
    int age = 19;
    float height = 1.79;
    double weight = 0.0;

    printf ("The Letter is: %c\n", letter);
    printf("The Name is: %s\n", name);
    printf("The Age is: %d\n", age);
    printf("The Height is: %.2f\n", height);
    printf("The Weight is: %.2f\n", weight);
    return 0;
}