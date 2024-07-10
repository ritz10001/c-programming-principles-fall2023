#include<stdio.h>

double integrate(double f(double), double a, double b); //function prototype

double integrate(double (*f)(double) , double a, double b){
    const int n=10000;
    double w=(b-a)/n;
    double sum=0;

    for(int i=0;i<n;i++){
        double x=a+(i+0.5)*w;
        double fx=f(x);
        sum+=fx*w;
    }
    return sum;

}

double sample_function(double x){
    return x*x;
}

int main(){

    double area=integrate(sample_function,1.0,3.0); //or *sample_function
    printf("%f", area);
    return 0;
}

