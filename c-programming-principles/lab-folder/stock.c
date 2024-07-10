#include<stdio.h>

float max(float s[]);

float min(float s[]);

int main(){


    float stocks[3][7] = {{45.2,44.8,44.5,45.6,45.75,45.9,45.4},{62.3,62.1,64.8,63.5,61.9,59.4,60.7},{30.75,34.25,32.90,29.80,31.20,33.10,30.95}};
    
    printf("Company 1: \n");
    printf("Average Closing Price: $%f\n", ((45.2+44.8+44.5+45.6+45.75+45.9+45.4)/7));
    printf("Highest Closing Price: $%f\n", (max(stocks[0])));
    printf("Lowest Closing Price: $%f\n", (min(stocks[0])));

    printf("Company 2: \n");
    printf("Average Closing Price: $%f\n", ((62.3+62.1+64.8+63.5+61.9+59.4+60.7)/7));
    printf("Highest Closing Price: $%f\n", (max(stocks[1])));
    printf("Lowest Closing Price: $%f\n", (min(stocks[1])));

    printf("Company 3: \n");
    printf("Average Closing Price: $%f\n", ((30.75+34.25+32.90+29.80+31.20+33.10+30.95)/7));
    printf("Highest Closing Price: $%f\n", (max(stocks[2])));
    printf("Lowest Closing Price: $%f\n", (min(stocks[2])));


    return 0;

}

float max(float s[]){
    int size=7;
    float current_max;
    for(int i=0;i<size;i++){
        if(current_max<s[i]){
            current_max=s[i];
        }
    }
    return current_max;

}

float min(float s[]){
    int size=7;
    float current_min=s[0];
    for(int i=0;i<size;i++){
        if(current_min>s[i]){
            current_min=s[i];
        }
    }
    return current_min;
}