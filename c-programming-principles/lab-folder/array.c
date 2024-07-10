#include<stdio.h>

void search(int a[], int element, int size);

void average(int a[], int length);

void odd_count(int a[] ,int length);

void even_count(int a[] ,int length);

int main(){

    int MyArray[] = {100,23,1,12,5,2,7,18,26,3,40,20,15,88};
    int search_num;


    printf("Enter the number you want to search");
    scanf("%d", &search_num);

    

    int size = sizeof(MyArray)/sizeof(MyArray[0]);

    search(MyArray,search_num,size);

    average(MyArray,size);

    return 0;
}

void search(int a[], int element, int size){
    int finish=0;

    for(int i=0;i<size;i++){
        if(a[i]==element){
            printf("Found element at: %d", i);
            break;
        }
        else{
            finish++;
            continue;
        }
    }
    if(finish==size){
        printf("No such element found");
    }
    
}

void average(int a[], int length){
    int total;
    for(int i=0;i<length;i++){
        total+=a[i];
    }
    float average=(float)total/length;
    printf("The average value of the elements are %f", average);
}

void odd_count(int a[] ,int length){
    int odd=0;

    for(int i=0,i<length;i++){
        if(a[i]%2!=0){
            odd++;
        }
    }

    printf("The number of odd numbers are %d", odd_count);


}


void even_count(int a[] ,int length){
    int even=0;

    for(int i=0,i<length;i++){
        if(a[i]%2==0){
            even++;
        }
    }

    printf("The number of even numbers are %d", even_count);


}


