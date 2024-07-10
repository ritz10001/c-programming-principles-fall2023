#include <stdio.h>


//MAIN ISSUE: YOU CANNOT INCLUDE ZEROES IN THE ARRAY AS ITS VERY DIFFICULT TO 
//PERFORM MANIPULATION OPERATIONS LIKE PUSH, POP IN A LANGUAGE LIKE C. SO 0 IS USED AS A REFERENCE
//TO AN ELEMENT THAT HAS BEEN POPPED

int subsetarray[3];

void solutionSubset(int subset[], int size);

void subsets(int arr[], int temp[], int index, int size);

int main(){

    int samplearr[] = {1,2,3};
    int temp[3]; //assigning a temp array which will be responsible for storing an subsets
    subsets(samplearr,temp,0,3);

    return 0;
}

void solutionSubset(int subset[], int size){
    printf("Subset: ");
    printf("{ ");
    for (int i = 0; i < size; i++) {
        if(subset[i]==0){
            continue;
        }
        else{
            printf("%d ", subset[i]);
        }
        
    }
    printf("}\n");
}

void subsets(int arr[], int temp[], int index, int size){
    if(index==size){  //BASE CASE
        solutionSubset(temp,size);
        return;
    }   

    temp[index]=arr[index]; //this is an alternative to pushing an element to the end of the array
    subsets(arr,temp,index+1,size); //RECURSIVE CASES
    temp[index]=0; // There is no direct way to pop or remove an element in c, so we just set it to 0 instead.
    subsets(arr,temp,index+1,size); //RECURSIVE CASES
}