#include <stdio.h>

int main(){
    int age, registration;
    char name[20];
    float height;

    printf("Enter your name: \n");
    scanf("%s", name);

    printf("Enter your age: \n");
    scanf("%d", &age);

    printf("Enter your height: \n");
    scanf("%f", &height);

    printf("Enter your registration: \n");
    scanf("%d", &registration);

    printf("Student's Names is: %s - Registration Number: %d - ", name, registration);
    printf("Age: %d - Height: %.2f", age, height);
}