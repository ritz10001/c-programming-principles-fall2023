#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//we can allocate specific amounts of memory. Ex we want a 3 byte instead of 4 byte from int type.

//first function - malloc (allocates a block of memory but does not initialize it)
//second - calloc (allocates a block of memory and clears it)
//third - realloc (resizes a previously allocated block of memory)

//these function return *void (generic pointer)
//if memory allocation is not successful, it returns a null pointer
//size_t is unsigned integer (only +ve)

//definition of malloc
//void *malloc(size_t size);

char *concat(const char *a, const char *b){
    char *result;
    result=malloc(strlen(a)+strlen(b)+1); //that last +1 finished with null character, it represents that

    //check
    if(result==NULL){
        printf(" Error malloc failed to allocate memory");
        exit(EXIT_FAILURE); //we dont use return because we dont return a pointer by just doing return;s
    }
    strcpy(result,a);
    strcat(result,b);
    return result;
}
int main() {
    //showing basic malloc
    //allocation 10 bytes of memory, it return "void"
    char *a = "te";
    char *b = "st";
    char *p = concat(a, b);
    printf("%s\n", p);

    free(p); //deallocates p, not doing so can lead to memory leaks

    

    //more advanced
    //casting malloc to return a pointer to an integer stored in q
    //int *q = (int *)malloc(sizeof(q));
    return 0;
}