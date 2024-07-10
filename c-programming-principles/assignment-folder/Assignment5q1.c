#include <stdio.h>

int recursive_multiplication(int x, int y){
    int mul=1;

    if(x==0 || y==0){  
        mul=0;
    }
    else if(y==1){ //BASE CASE
        mul=x;
    }
    else{ //RECURSIVE CASE
        mul=recursive_multiplication(x,y-1)+x;
    }
    return mul;
}

int main(){
    //THE PROGRAM WILL NOT STOP USER FROM ENTERING FLOATING NUMBERS AS THAT CASE IS QUITE COMPLEX TO HANDLE.
    //INSTEAD, ANY FLOATING NUMBERS ENTERED WILL AUTOMATICALLY BE CASTED TO INTEGERS BEFORE BEING PASSED INTO THE FUNCTION.
    int a;
    int b;
    printf("Enter the first number: ");
    int res1 = scanf("%d", &a);
    while (getchar() != '\n'); //this just clears input buffer in case user enters floating number. This will prevent the code from breaking.
    printf("Enter the second number: ");
    int res2 = scanf("%d", &b);
    while (getchar() != '\n');

    

    if(res1!=1 || res2!=1 || a<0 || b<0){
        printf("Invalid Input(s)! Please try again!\n");
    }
    else{
        int result = recursive_multiplication((int)a,(int)b);
        printf("The product of numbers: %d\n", result);
    }

    return 0;
}

