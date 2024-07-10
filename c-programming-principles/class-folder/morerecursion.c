#include<stdio.h>


int factorial(int n);
int fibonacci(int n);

int main(){
    int d=6;
    printf("printing the first 5 numbers of fibonacci serial\n");
    for(int i=1;i<=6;i++){
        printf("%d\n", fibonacci(i));
    }
    return 0;
}

// int factorial(int n){
//     if(n==0 || n==1){
//         return 1;
//     }
//     else{
//         return n*factorial(n-1);
//     }
// }


int fibonacci(int n){
    //1,1,2,3,5,8.13
    int fibsum=0;

    if(n<=2){
        fibsum=1;
    }
    else{
        fibsum=fibonacci(n-1)+fibonacci(n-2);
    }

}
