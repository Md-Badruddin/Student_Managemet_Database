
#include <stdio.h>
int main() {
    int choice;
    float c,f;
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nChoose: ");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter Celsius: "); scanf("%f",&c);
        f = (c*9/5)+32;
        printf("%.2f Celsius = %.2f Fahrenheit\n",c,f);
    } else if(choice==2){
        printf("Enter Fahrenheit: "); scanf("%f",&f);
        c = (f-32)*5/9;
        printf("%.2f Fahrenheit = %.2f Celsius\n",f,c);
    } else{
        printf("Invalid choice\n");
    }
    return 0;
}
