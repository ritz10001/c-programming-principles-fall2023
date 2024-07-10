#include<stdio.h>

double calculateCharge(char serviceCode, double peakUsage, double offPeakUsage);

int main(){

    long accountNum;
    char serviceCode;
    float peakUsage;
    float offPeakUsage;
    double netCharge;

    int result1;
    int result2;
    int result3;
    
    printf("Enter account number: ");
    result1=scanf("%ld", &accountNum);

    if(result1!=1){
        printf("Please enter a valid account number\n");
        return 0;
    }

    printf("Enter service code (R for Residential, C for Commercial): ");
    scanf(" %c", &serviceCode);

    
    

    printf("Enter usage in peak hours (kWh): ");
    result2=scanf("%f", &peakUsage);

    if(result2!=1){
        printf("Please enter a valid value!\n");
        return 0;
    }

    printf("Enter usage in off-peak hours (kWh): ");
    result3=scanf("%f", &offPeakUsage);

    if(result3!=1){
        printf("Please enter a valid value!\n");
        return 0;
    }
    




    switch(serviceCode){
        case 'R':
            netCharge=calculateCharge(serviceCode,peakUsage,offPeakUsage);
            break;
        case 'C':
            netCharge=calculateCharge(serviceCode,peakUsage,offPeakUsage);
            break;
        case 'r':
            netCharge=calculateCharge(serviceCode,peakUsage,offPeakUsage);
            break;
        case 'c':
            netCharge=calculateCharge(serviceCode,peakUsage,offPeakUsage);
            break;
        default:
            break;

    }   

    if(serviceCode!='R' && serviceCode!='r' && serviceCode!='C' && serviceCode!='c'){
        printf("Invalid service code!\n");
        return 0;
    }

    printf("\n");
    printf("\n");

    printf("Electricity Bill\n");
    printf("Account Number: %ld\n", accountNum);
    if(serviceCode=='R' || serviceCode=='r'){
        printf("Service Type: Residential\n");
    }
    else if(serviceCode=='C' || serviceCode=='c'){
        printf("Service Type: Commercial\n");
    }
    printf("Usage in Peak Hours: %.2f kWh\n", peakUsage);
    printf("Usage in Peak Hours: %.2f kWh\n", offPeakUsage);
    printf("Amount due: $%.2f\n", netCharge);
    


    return 0;
}

double calculateCharge(char serviceCode, double peakUsage, double offPeakUsage){
    float peakCharge=0;
    float offPeakCharge=0;

    if(serviceCode=='R' || serviceCode=='r'){
        peakCharge=peakUsage*0.15;
        offPeakCharge=offPeakUsage*0.1;
    }
    else if(serviceCode=='C' || serviceCode=='c'){
        peakCharge=peakUsage*0.2;
        offPeakCharge=offPeakUsage*0.15;
    }

    float finalCharge=peakCharge+offPeakCharge;
    return finalCharge;





}