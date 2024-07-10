#include<stdio.h>

//float calculate_bill(float price);

float tip_percent_entry();

int main(){
    float bill_amt;
    int no_of_people;
    float tip_percentage;
    float bill_withtax;
    float tax_amount;
    float tip_per_person;
    
    printf("enter the bill amount\n");
    scanf("%f", &bill_amt);
    // a separate method is made for tip_percentage in case the user enters an invalid tip percentage
    tip_percentage=tip_percent_entry();

   
    
    printf("enter the number of people\n");
    scanf("%d", &no_of_people);

    tax_amount = bill_amt * 0.16;
    bill_withtax = bill_amt + tax_amount;

    printf("The tax: %.2f%s\n", tax_amount, " $");
    printf("The bill after the tax is applied: %.2f%s\n", bill_withtax, " $");

    tip_per_person = (bill_withtax * tip_percentage)/no_of_people;

    //printf("tip percentage: %f\n",tip_percentage);
    printf("The tip per person: %.2f%s\n", tip_per_person, " $");
    printf("The amount per person including tip: %.2f%s\n", ((bill_withtax/no_of_people)+tip_per_person), " $");
    return 0;




}

float tip_percent_entry(){
    float tip_percentage;
    printf("enter the tip percentage (0.1, 0.15, or 0.2)\n");
    scanf("%f", &tip_percentage);
    if(tip_percentage!=0.1f && tip_percentage!=0.15f && tip_percentage!=0.2f){
        printf("please enter a valid tip percentage\n");
        tip_percentage=tip_percent_entry();
    }
    return tip_percentage;
}

