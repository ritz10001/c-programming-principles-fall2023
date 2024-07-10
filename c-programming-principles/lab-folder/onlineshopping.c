#include<stdio.h>

int main(){

    int total_cost;
    float discount;

    printf("Enter the total cost of the order");
    scanf("%d",&total_cost);
    if(total_cost>=100){
        discount=0.1f*total_cost;
    }
    else if(total_cost>=50 && total_cost<100){
        discount=0.05f*total_cost;
    }
    else{
        discount=0;
    }
    printf("The new cost with the discount is %f", total_cost-discount);

    return 0;
}