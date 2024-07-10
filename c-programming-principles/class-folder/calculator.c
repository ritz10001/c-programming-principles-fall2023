#include<stdio.h>

int main(){

    char operator;
    float num1;
    float num2;
    float res;

    printf("enter the choice");
    scanf("%c",&operator);


    switch(operator){
        case '+':
            printf("enter the first number");
            scanf("%f", &num1);
            printf("enter the second number");
            scanf("%f", &num2);
            res = num1 + num2;
            printf("the result is %f", res);
            break;
        case '-':
            printf("enter the first number");
            scanf("%f", &num1);
            printf("enter the second number");
            scanf("%f", &num2);
            res = num1 - num2;
            printf("the result is %f", res);
            break;
        case '*':
            printf("enter the first number");
            scanf("%f", &num1);
            printf("enter the second number");
            scanf("%f", &num2);
            res = num1 * num2;
            printf("the result is %f", res);
            break;
        case '/':
            printf("enter the first number");
            scanf("%f", &num1);
            printf("enter the second number");
            scanf("%f", &num2);
            if(num2==0){
                printf("denominator cannot equal 0!");
                break;
            }
            res = num1 / num2;
            printf("the result is %f", res);
            break;
        default:
            break;
        
    

    };
    return 0;
}