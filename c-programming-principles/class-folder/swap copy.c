#include<stdio.h>

void swap(int a, int b);

int main(){
    int a=2;
    int b=3;
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    swap(a,b);
    printf("after swap process");
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    //after executing we notice the value of a and b remain the same, they don't change. We need to pass by reference
    
    return 0;
}

void swap(int a, int b){
    int temp=a;
    a=b;
    b=temp;
}