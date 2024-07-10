#include<stdio.h>


int dectobin(int n){
    if(n==0){
        return 0;
    }
    else{
        printf("%d", n%2); //1 0 0 1 1 
        dectobin((int)n/2);
    }
}


int cal_power(int a, int b){

    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }
    else{
        return a*cal_power(a,b-1);
    }
}

int binary_search(int target, int arr[], int left, int right){

    if(left>right){
        return -1;
    }
    int mid=(int)(left+right)/2;

    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<target){
        return binary_search(target, arr, mid+1, right);
    }
    else{
        return binary_search(target, arr, left, mid-1);
    }

}

int recursive_sum(int arr[], int size){

    int sum=arr[size];
    if(size==0){
        return arr[0];
    }
    else{
        sum+=recursive_sum(arr, size-1);
    }
    return sum;
}
int main(){

    //dectobin(25);

    // int res = cal_power(2,0);
    // printf("%d", res);

    int search[] = {1,2,4,5,6,11,15,16,22,28,34,38,44};
    int size = (int)sizeof(search)/sizeof(search[0]);


    // int res = binary_search(21,search,0,size);
    // printf("%d", res);

    int res = recursive_sum(search, size);
    printf("%d", res);

    return 0;
}