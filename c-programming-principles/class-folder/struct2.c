#include<stdio.h>
#include<string.h>



struct part{
    int number;
    char name[20];
    int on_hand;

};

void print_struct(struct part x){

    printf("%d",x.number);
    printf("%s",x.name);
    printf("%d", x.on_hand);


}

struct part function1(int a,char n[], int b){
    struct part p;
    p.number=a;
    strcpy(p.name,n); //copies string content of n to p.name 
    p.on_hand=b;

    return p;


}
int main(){
    struct part a={100,"Disk Drive", 5};

    

    struct part b={200, "Hard Disk", 20};

    print_struct(b);

    struct part res = function1(10, "SOMETHING", 200);
    printf("AFTER");
    printf("%d",res.number);
    printf("%s",res.name);
    printf("%d", res.on_hand);

    //shorthand
    //print_struct((struct part) {100, "Disk Drive",5});
    


    return 0;
}





