#include<stdio.h>
#include<math.h>

int main(){


    int n;

    printf("enter the value of n");

    scanf("%d", &n);

    printf("n\tn^2\tn^3\tn^4\n");

    for(int i=0;i<=n;i++){
        printf("%d\t%.1f\t%.1f\t%.1f\n",i,pow(i,2),pow(i,3),pow(i,4));
    }
    return 0;

}