#include<stdio.h>


void increment_pass_by_value(int *x){
    x++;
}

void increment_pass_by_reference(int *x){
    (*x)++;
}

int *max(int *a, int *b){ //pointer returning functions
    printf("%p", a); 
    printf("%p", b);
    if(*a>*b){
        return a;
    }
    else{
        return b;
    }
}


int *f(){
    int i;
    return &i; //i doesnt exist outside the scope of this function so error
}
int main(){
    // int num=5;
    // printf("num value before the function call: %d\n",num);
    // increment_pass_by_reference(&num); //if we use pass by value no change but passbyreference it changes
    // printf("num value before the function call: %d\n",num); 


    // int i,*p;
    // p=&i;
    // scanf("%d", p);
    // printf("The value of i is %d", i);

    //pointer functions


    // int *p,i=20,j=78;
    // p=max(&i,&j);
    // printf("max of %d and %d is: %d", i,j,*p);

    // int *k=f(5);

    // int a[5]={1,2,3,4,5}, *p, q;
    // p=&a[0];
    // *q=&a[4];
    // for(int r=0;r<5;r++){
    //     printf("%d", a[r]);
    // }

    //pointer arithmetic
    //if p points to a[i], then p+j points to a[i+j]
    int *p, a[10], i, *q;
    a={1,2,3,4,5,6,7,8,9,10};
    p=&a[2];
    q=p+3;
    p+=6; //check notes to understand how this works
    printf("%d", *q);
    printf("%d", *p); //we can do the same for subtraction




    return 0;

}