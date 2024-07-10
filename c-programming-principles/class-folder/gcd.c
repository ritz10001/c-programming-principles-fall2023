#include<stdio.h>

int main(){
    int m=100
    int n=21;

    return 0;
}

static int i=0;
int gcd(int m, int n){
    int ans;
    if(m%n==0){
        ans=n;
        i++;
    }
    else{
        gcd(n,m%n); 
        i++;
        return ans;
        //in case of 105 and 55
        //105%55=50 pass through gcd(55,50), then we get 5 so then gcd(50,5) we get 0 so 5 is answer
    }
}

