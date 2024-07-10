#include<stdio.h>

int main(){
    float fuel_efficiency;

    printf("enter the cae's fuel efficiency");
    scanf("%f", &fuel_efficiency);

    

    if(fuel_efficiency>=40){
        printf("fuel efficient");
    }else if(fuel_efficiency>=25 && fuel_efficiency<40){
        printf("moderate fuel efficiency");
    }
    else{
        printf("low fuel efficiency");
    }

    return 0;

}