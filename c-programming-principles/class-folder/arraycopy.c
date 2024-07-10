#include<stdio.h>

int main(){

    // int a[5]={1,2,3,4,5};
    // int b[5];
    //to copy a elements to b, the only way is to use a for loop


    struct{
        int number;
        char name[20];
        int on_hand;

    }a={20,"Disk Drive", 15}, b;
    //int a[]={1,2,3,4,5}, b[5];
    //b=a  WE CANT DO THIS, HOWEVER WE CAN DO THIS FOR STRUCTS
    b=a;
    printf("%d", a.number);
    printf("b.number = %d", b.number);

    //THE POINT of this is that we can create an array inside a struct and then copy that array
    struct{
        int c[5];
    }d,e;
    d.c[0]=1;
    d.c[1]=13;
    d.c[2]=55;
    d.c[3]=34;
    d.c[4]=19;
    e=d;
    printf("e.a[0]=%d", e.c[0]);

    struct part{
        int number;
        char name[20];
        int on_hand;
    }f={20, "Disk Drive", 15},g[20] ,h; //here f and h are structs, g is array of structs

    b[4].number=100;
    b[9].name[0]='a';

    x=f;
    struct part p,q,r;
    p=x;

    // we can also use typedef that way we wont have to write struct followed by struct name.
    // we can directly do it

    //we can also create an array of structs



    return 0;



}