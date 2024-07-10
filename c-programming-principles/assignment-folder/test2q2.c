#include <stdio.h>

int *findMax(int arr[], int size) {
    if (size == 0) {
        return NULL; 
    }

    int *maxElement = &arr[0];

    // simple algorithm for finding the maximum element

    for (int i = 1; i < size; i++) {
        if (arr[i] > *maxElement) {
            maxElement = &arr[i];
        }
    }

    return maxElement;
}



int multiplyrecursive(int arr[], int size) {
    if (size == 0) {
        return 1;
    } 
    else {
        return arr[size - 1] * multiplyrecursive(arr, size - 1);
    }
}


void circularShift(int arr[], int size, int shiftBy) {

    int temp; //we use this to swap 2 elements

    for (int i = 0; i < shiftBy; i++) {
        temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}



int main() {
    int myarray[] = {1, 3, 4, 20, 100, 12};
    int size = sizeof(myarray) / sizeof(myarray[0]);

    //THIS IS FOR THE FIRST FUNCTION

    int *maxElement = findMax(myarray, size);

    if (maxElement != NULL) {
        printf("Maximum element in the array is: %d\n", *maxElement);
    } 
    else {
        printf("Empty Array!.\n");
    }

    //THIS IS FOR THE SECOND FUNCTION

    int result = multiplyrecursive(myarray, size);

    printf("Multiplication result is: %d\n", result);

    //THIS IS FOR THE THIRD FUNCTION

    int shiftBy = 2;

    circularShift(myarray, size, shiftBy);

    printf("Array after circular shift by the right by %d positions:  ", shiftBy);
    for (int i = 0; i < size; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");

    return 0;
}
