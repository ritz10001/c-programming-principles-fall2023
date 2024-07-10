#include<stdio.h>
#include<string.h>
#define MAX_NAME_LENGTH 50



//void add_student(struct student students[50], char name[MAX_NAME_LENGTH], int number, int marksobt);
//void displaystudent(struct student stud);

struct student{
    char name[MAX_NAME_LENGTH];
    int rnumber;
    int marks;


};

void displaystudent(struct student stud){
    printf("Name: %s", stud.name);
    printf("R Number: %d", stud.rnumber);
    printf("Marks: %d", stud.marks);
    printf("\n");
}

void add_student(struct student students[50], int numstudents, char name[MAX_NAME_LENGTH], int number, int marksobt){
    if(numstudents<50){
        struct student newstudent;
        strncpy(newstudent.name,name,sizeof(name));
        newstudent.rnumber=number;
        newstudent.marks=marksobt;

        students[numstudents]=newstudent;
        displaystudent(newstudent);
        return;

    }
    else{
        printf("Limit exceeded");
        return;
    }
    
}   
int main(){
    //int studentnumber=0;
    // struct student s1;
    // struct student s2;
    struct student arr[50];

    add_student(arr, 0, "somebody", 118452, 90);

    //printf()
    return 0;
}