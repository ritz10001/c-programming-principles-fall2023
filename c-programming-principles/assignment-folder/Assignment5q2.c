#include <stdio.h>
#include <string.h>


void generate_stars(int x){

    char star[1000]="";

    if(x==0){ //BASE CASE
        strcat(star,"*");
        return;
    }
    else if(x==1){
        strcat(star,"*");
        printf("%s",star);
        printf("\n");
        generate_stars(x-1);
        printf("%s",star);
        printf("\n");
    }

    else if(x>1){
        for(int i=0;i<x;i++){
            strcat(star,"*");
        }
        printf("%s",star);
        printf("\n");
        generate_stars(x-1);
        printf("%s",star);
        printf("\n");
    }
    else{
        generate_stars(x-1);
        printf("%s",star);
        printf("\n");
    }
}

int main(){

    //FLOAT NUMBERS ARE AUTOMATICALLY CASTED AND ROUNDED DOWN TO THE CLOSEST INTEGER

    int star_count;

    printf("Enter the asterisk pattern number: ");
    int res=scanf("%d", &star_count);

    if(res!=1 || star_count<0){
        printf("Please enter a valid input!\n");
    }

    else{
        generate_stars(star_count);
    }

    return 0;
}