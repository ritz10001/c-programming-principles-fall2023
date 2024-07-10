#include<stdio.h>

int main(){
    int gs1,gi,pc,inum,ck;
    printf("go ahead\n");
    scanf("%d-%d-%d-%d-%d",&gs1,&gi,&pc,&inum,&ck);

    printf("The ISBN IS %d%d%d%d%d\n",gs1,gi,pc,inum,ck);
    printf("GS1 Prefix: %d\n Group Identifier: %d\n Publisher Code: %d\n I number: %d\n Check Number %d",gs1,gi,pc,inum,ck);

    return 0;
}