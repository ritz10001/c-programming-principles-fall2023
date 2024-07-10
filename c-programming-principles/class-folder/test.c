#include <stdio.h>





typedef struct{
    char something[100000000];
    int somenum;
}Newstruct; 





int main(){
    Newstruct instance;
    instance.something="f";

    return 0;
}
