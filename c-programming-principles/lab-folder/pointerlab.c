#include <stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}

void dispense(int total, int *hundreds, int *fifty, int *twenty, int *ten){
    
    *hundreds = total/100;
    total = total%100;

    *fifty = total/50;
    total = total%50;

    *twenty = total/20;
    total = total%20;

    *ten = total/10;
    total = total%10;




}

int main(){

    // int a=42;
    // int b=7;
    // int c=999;
    // int *t=&a;
    // int *u=NULL;
    // printf("%d %d\n",a,*t);
    // c=b;
    // u=t;
    // printf("%d %d\n",c,*u);

    // a=8;
    // b=8;
    // printf("%d %d %d %d\n",b,c,*t,*u);

    // *t=123;
    // printf("%d %d %d %d %d\n", a,b,c,*t,*u);

    // //updating t to point to c
    // t=&c;
    // *t=555;
    // printf("the new value of c %d\n", c);

    // //changing value of c using direct assignment

    // c=222;
    // printf("the new value of c yet again %d\n", c);

    // //random stuff
    // int *v=t;
    // printf("%d\n", *v);

    // int a=10;
    // int b=20;
    
    // swap(&a,&b);
    // printf("the new value of a %d\n", a);
    // printf("the new value of b %d\n", b);
    int ten,twenty,fifty,hundred;
    ten=0;
    twenty=0;
    fifty=0;
    hundred=0;
    dispense(124150,&hundred,&fifty,&twenty,&ten);
    printf("hundreds: %d\n", hundred);
    printf("fifty: %d\n", fifty);
    printf("twenty: %d\n", twenty);
    printf("ten: %d\n", ten);



    

    return 0;
}


