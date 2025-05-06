#include <stdio.h>

int main(){
    char letter;
    char name[20];
    int age;
    float height;

    printf("Enter your letter: ");
    scanf("%c", &letter);
    printf("Your letter is: %c\n", letter);
    
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Your name is: %s\n", name);
        
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age is: %d\n", age);
        
    printf("Enter your height: ");
    scanf("%f", &height);
    printf("Your height is: %.2f\n", height);
}