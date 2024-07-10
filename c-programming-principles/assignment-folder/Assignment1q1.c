#include<stdio.h>

//Question 1
float gotham_population_function(int t);
int year_entry();

int main(){
    int year=year_entry();
    if(year<1990){
        printf("Please enter a valid year\n");
        year=year_entry();
    }
    float predicted_population = gotham_population_function(year-1990);
    printf("The predicted population for the year (in thousands) %d is: %.3f\n",year,predicted_population);
    return 0;


}
int year_entry(){
    int year;
    printf("Enter an year after 1990: ");
    scanf("%d",&year);
    return year;
}


float gotham_population_function(int t){
    float model = 52.966 +2.184*t;
    return model;
}