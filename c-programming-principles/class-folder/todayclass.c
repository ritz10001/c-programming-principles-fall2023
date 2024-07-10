#include<stdio.h>

int main(){

    int a[10] ={1,2,3,4,5,6,7,8,9,10};
    // for(int i=0;i<10;i++){
    //     printf("%d\n",a[i]);
    // }

    //int a[10]={}; this is illegal
    //even assigning more stuff than the length of the array is illegal

    //4 bytes=32 bits
    ///0= 00000
    int byteLength = sizeof(a); //return byte length each integer is 4 bytes
    //to get numeric length, divide by individual bytecount
    int arrayLength = byteLength/sizeof(a[0]);
    printf("%d",arrayLength);

    //what if we want to initialize only a few ints
    int b[10] = {0,1,0,0,0,2,0,0,0,0}; //one way of doing but not good
    //desginated initialization
    int c[10]={[3]=5,[8]=6};

    //if you do m[i,j] in indexing c will treat it as m[j] only the i gets discarded

    printf("the element of b %d", b[0,1]);

    //multidimensional arrays
    int d[3][4] = {
        {0,0,0,0},{1,1,1,1},{2,2,2,2}
    };
    




    return 0;

}

