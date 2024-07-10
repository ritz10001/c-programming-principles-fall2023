#include<stdio.h>


struct point{
    int x;
    int y;
};

void *calloc(size_t nmemb, size_t size){
    //allocates space for an array with nmemb elements, each of which is size bytes long
    //returns a null pointer if the requested space isnt available
    //initializes allocated memory by setting all bits to 0.
    
}

int main(){

    int *arr;
    int size;

    scanf("%d", &size);

    arr = calloc(size,sizeof(struct point));




    return 0;
}