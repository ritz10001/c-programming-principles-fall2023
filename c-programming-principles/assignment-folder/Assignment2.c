#include<stdio.h>

void info(long accnum, char servicecd, int dayminutes, int nightminutes, float bill);

int main(){
    unsigned long accnum;
    char servicecd;
    int dayminutes;
    int nightminutes;
    float bill;

    printf("Enter your account number: ");
    scanf("%ld", &accnum);

    printf("Enter the service code: ");
    scanf(" %c", &servicecd);

    if(servicecd=='r' || servicecd=='R'){
         printf("Enter the number of minutes the service was used: ");
         scanf("%d", &dayminutes);
         bill = (dayminutes%50>0 && dayminutes>50)?(0.2f*(dayminutes-50)+10):10;
         info(accnum,servicecd,dayminutes,0,bill);

    }
    else if(servicecd=='p' || servicecd=='P'){
        printf("Enter the number of minutes the service was used in the day: ");
        scanf("%d", &dayminutes);
        printf("Enter the number of minutes the service was used at night: ");
        scanf("%d", &nightminutes);
        bill += (dayminutes%75>0 && dayminutes>75)?(0.1f*(dayminutes-75)+25):25;
        bill += (nightminutes%100>0 && nightminutes>100)>0?(0.05f*(nightminutes-100)):0;
        info(accnum,servicecd,dayminutes,nightminutes,bill);

    }
    else{
        printf("Error! Invalid service type!\n");
    }

    return 0;

}

void info(long accnum, char servicecd, int dayminutes, int nightminutes, float bill){
    if(servicecd=='r' || servicecd=='R'){
        printf("Account number: %ld\n", accnum);
        printf("Service type: Regular\n");
        printf("Number of minutes of service used: %d\n", dayminutes);
        printf("Amount due: $%f\n", bill);
    }

    else{
        printf("Account number: %ld\n", accnum);
        printf("Service type: Premium\n");
        printf("Number of minutes of service used during the day: %d\n", dayminutes);
        printf("Number of minutes of service used during the night: %d\n", nightminutes);
        printf("Amount due: $%f\n", bill);
    }
}


