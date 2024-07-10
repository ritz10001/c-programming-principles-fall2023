#include<stdio.h>
#include<math.h>




int largest_of_three(int a,int b, int c);

float absolute(float num);

int leading_digit(int value);

float end_amount(float p,float r,float a, int n){
    return p*pow((1+r),n);
}

void sort_arr(int arr[],int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The new array: \n");
    for(int z=0;z<size;z++){
        printf("%d", arr[z]);
    }
}

float calculate_overdue(int days){
    if(days<0){
        printf("Please enter a valid day count");
        return 0.0;
    }
    return 0.25*days;
}

int main(){

    // int a,b,c;

    // printf("Enter the first number: ");
    // scanf("%d", &a);
    // printf("Enter the second number: ");
    // scanf("%d", &b);
    // printf("Enter the third number: ");
    // scanf("%d", &c);

    // int largest = largest_of_three(a,b,c);
    // printf("The largest off the three: %d", largest);

    // float real_num;

    // printf("Enter any real number");

    // scanf("%f", &real_num);
    // float abs_value = absolute(real_num);

    // printf("The absolute value: %.f", abs_value);

    // int leading_number;
    // printf("Enter any integer");
    // scanf("%d", &leading_number);
    // int result = leading_digit(leading_number);
    // printf("The leading digit is: %d", result);


    // float p,r,a;
    // int n;

    // printf("Enter the original amount invested: ");
    // scanf("%f", &p);
    // printf("Enter the annual interest rate: ");
    // scanf("%f", &r);
    // printf("Enter the number of years: ");
    // scanf("%d", &n);
    // printf("Enter the amount of deposit by the nth year: ");
    // scanf("%f", &a);

    // float result_amount=end_amount(p,r,a,n);

    // printf("The result is: %f", result_amount);

    // int arr[]={5,1,4,2,8};
    // sort_arr(arr,5);


    int days;
    printf("Enter the amount of days the book is overdue");
    scanf("%d", &days);
    float overdue_amount=calculate_overdue(days);







    return 0;
}

int largest_of_three(int a,int b, int c){

    if(a>b){
        if(a>c){
            return a;
        }
        else{
            return c;
        }
            
        
    }
    else{
        if(b>c){
            return b;
        }
        else{
            return c;
        }
    }

}

float absolute(float num){
    if(num>0){
        return num;
    }
    else{
        return num*-1;
    }
}

int leading_digit(int value){

    while(value>=10){
        value=value/10;
    }

    return value;

}

