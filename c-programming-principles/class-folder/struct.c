#include <stdio.h>
#include <string.h>


struct {
    int number;
    char name[20];
    int on_hand;

}a={20, "Disk Drive", 15},b={.number=23, .on_hand=5, .name="CD"}, //its called designated initializer.
c={.name="Floppy", .on_hand=7}, //the .number will get initialized to 0.
d={.number=23, "Hard Disk", .on_hand=5}; //this will only work so as long as the positions arent different.


struct{
    int number;
    double id;
    float coursegrade;
}a,student2;

int a=10;

int main(){
    printf("%d", b.number);
}