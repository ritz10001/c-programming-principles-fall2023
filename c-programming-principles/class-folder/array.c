#include<stdio.h>

int array_sum(int []);

int main(){

    int a[7]={4,5,8,9,12,11,2};
    int return_sum=array_sum(a);
    printf("The sum of the array is: %d\n", return_sum);
    return 0;
}

int array_sum(int arr[]){
    int sum=0;
    printf("The size of the array is: %ld\n",sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        sum+=arr[i];
    }
    return sum;
}


