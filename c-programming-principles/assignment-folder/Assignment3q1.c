#include<stdio.h>
#include<math.h>


void calculate(int a_population, int b_population, float a_growth, float b_growth);

int main(){
    int a_population;
    int b_population;
    float a_growth;
    float b_growth;
    printf("Enter the population of Town A: ");
    scanf("%d", &a_population);
    printf("Enter the growth rate of Town A (in percentage): ");
    scanf("%f", &a_growth);

    printf("Enter the population of Town B : ");
    scanf("%d", &b_population);
    printf("Enter the growth rate of Town B in percentage): ");
    scanf("%f", &b_growth);
    a_growth=a_growth/100;
    b_growth=b_growth/100;

    if(b_growth>=a_growth || a_population>=b_population){
        if(a_population>=b_population){
            printf("Given the current values, Town A is already ahead of Town B!\n");
        }
        else{
            printf("Given the current values, Town A will never overtake Town B!\n");
        }
        
        return 0;
    }

    calculate(a_population,b_population,a_growth,b_growth);

    
    return 0;
}

void calculate(int a_population, int b_population, float a_growth, float b_growth){
    int year_count=0;
    float projected_a_population=a_population;
    float projected_b_population=b_population;
    while(projected_b_population>=projected_a_population){
        year_count++;
        projected_a_population+=projected_a_population*(a_growth);
        projected_b_population+=projected_b_population*(b_growth);
       

    }   
    printf("Town A will surpass Town B in population after %d years.\n", year_count);
    printf("Population of Town A %d\n", (int)round(projected_a_population));
    printf("Population of Town B %d\n", (int)round(projected_b_population));
}
