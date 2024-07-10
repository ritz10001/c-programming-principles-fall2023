#include<stdio.h>
#include<stdbool.h>

bool searchElement(int arr[], int element, int size){
    int counter=0;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return true;
            break;
        }
        else{
            counter++;
            continue;
        }
    }
    if(counter==size){
        return false;
    }
    
}

float findAverage(int arr[], int size){
    float sum;
    float average;

    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    average=sum/size;
    return average;
}

int count(int arr[], int size){

    int evenCount=0;
    int oddCount=0;
    for(int i=0;i<size;i++){
        if(arr[i]%2==0){
            evenCount++;
        }
        else{
            oddCount++;
        }
    }
    printf("Number of even numbers in the array (INCLUDING 0): %d\n", evenCount);
    printf("Number of odd numbers in the array: %d\n", oddCount);
}

int main(){

    int MyArray[] = {50,23,4,12,5,2,0,18,26,3,40,20,15,66};
    int size=sizeof(MyArray)/sizeof(MyArray[0]);
    int element;

    printf("Enter the element you want to search: ");
    scanf("%d", &element);
    bool result=searchElement(MyArray,element,size);
    if(result==true){
        printf("Yes, the element has been found!\n");
    }
    else{
        printf("No, the element has not been found!\n");
    }

    printf("\n");

    float avg=findAverage(MyArray,size);
    printf("Average of the numbers in the array: %f\n", avg);
    printf("\n");

    count(MyArray,size);




    return 0;
}

