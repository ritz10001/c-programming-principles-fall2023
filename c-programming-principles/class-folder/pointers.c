#include<stdio.h>

void decompose(double x, long *int_part, double *frac_part);

int main(){

    //every variable is stored in memory and they have a unique address.
    //A variable may use more than 1 byte, but we will refer to it's address only from the first byte

    //address of a variable can be stored in a special pointer variable
    
    // int a=10,*p,b[10]; //this is a pointer variable, it will point to some integer object

    // //initially, *p points to nowhere in particular

    // p=&a; //ampersand refers to the address. p is pointing to the address of a the variable 

    // printf("THE ADDRESS THAT P POINTS TO\n");
    // printf("%p\n", p); //this will print out the address of a.

    // //IMPORTANT: WE CAN ONLY POINT A POINTER VARIABLE TO ANOTHER VARIABLE IF THEY ARE OF THE SAME TIME
    // //eg. int pointer variable will only point to another int variable, and so on.

    // //To find to the object the pointer points to, we use the *(indirection) operator.

    // printf("%d\n", *p); 


    // //what if we did this?
    // printf("%d", *&a);

    // //lets do this
    // int c,i=1;
    // c=&i;
    // *c=2;
    // //this will change the value of i to 2 as well
    
    // int j=10;
    // int k=20;

    // int *y;
    // int *z;

    // y=&j;
    // z=&k;

    // int *v = y;

    // int *q,a=10,*p,b;

    // q=&a;
    // p=&b;
    
    // p=q; //if we said *p=*q that doesnt change any pointer stuff but doing this does
    // *q=20;
    
    // printf("%d", b);

    // int i=0;
    // float d=0;

    // printf("i = %d, d = %f\n",i,d);
    // decompose(1.51,&i,&d); //passing in the addresses of these variables
    // printf("i = %d, d = %f\n",i,d);

    int a[10];
    *a=10;
    *(a+1)=12; //== a[1] = 12;
    *(a+5)=20;
    *(a+9)=100;

    for(p=a;p<a;p++){
        *p=0;
        *a=10;
        *(a+1)=12; //== a[1] = 12;
        *(a+5)=20;
        *(a+9)=100;

        --p;
    }




    return 0;
}


void decompose(double x, long *int_part, double *frac_part){
    *int_part=(int)x;
    *frac_part=x-*int_part;
}
