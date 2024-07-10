#include<stdio.h>


int multiply(int a,int b);
void reverse_input_string(int n);

int main(){
    //int result=multiply(10,20);
    //printf("the result is %d", result);
    reverse_input_word(5);
    return 0;
}

// int multiply(int a, int b){
//     int res;
//     if(b==1){
//         res=a;
//         return res;
//     }
//     else{
//         res=multiply(a,b-1)+a;
//         return res;
//     }

// }

void reverse_input_word(int n){
    char word[1000];
    if(n<=1){
        scanf("%s",word);
        printf("%s ", word);
    }
    else{
        scanf("%s",word);
        reverse_input_word(n-1);
        printf("%s ", word);
    }
}