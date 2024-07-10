#include<stdio.h>

int main(){

    int hot_days=0;
    int pleasant_days=0;
    int cold_days=0;


    while(1){
        char choice;
        printf("any key to continue or press E/e to exit the loop");
        scanf("%c", &choice);
        if(choice=='e' || choice=='E'){
            break;
        }
        int temp;
        printf("enter the temperature\n");
        scanf("%d", &temp);
        if(temp>=85){
            printf("HOT\n");
            hot_days++;
        }
        else if(temp<=84 && temp>=60){
            printf("PLEASANT\n");
            pleasant_days++;
        }
        else{
            printf("COLD\n");
            cold_days++;
        }
    }

    printf("HOT DAYS: %d\n", hot_days);
    printf("PLEASANT DAYS: %d\n", pleasant_days);
    printf("COLD DAYS: %d\n", cold_days);
    return 0;
}