#include<stdio.h>
#include<string.h>
#define MAX_BOOK_SIZE 50
#define MAX_AUTHOR_NAME 50



// struct person{
//     char name[50];
//     int age;
//     float height;
// };

// void storeperson(struct person persons[3],int limit, char personname[50], int personage, int personheight){
//     if(limit>3){
//         printf("You have reached the limit of adding people!");
//         return;
//     }
//     else{
//         struct person newperson;
//         strncpy(newperson.name,personname,sizeof(personname));
//         newperson.age=personage;
//         newperson.height=personheight;
//         persons[limit]=newperson;
//         //limit++;
//         return;
//     }
// }

// void showperson(struct person persons[3]){
//     for(int i=0;i<3;i++){
//         printf("The name of the person : %s\n",persons[i].name);
//         printf("The age of the person : %d\n", persons[i].age);
//         printf("The height of the person : %f\n", persons[i].height);

//     }
// }




struct book_library{
    char name[MAX_BOOK_SIZE];
    char author[MAX_AUTHOR_NAME];
    long isbn;
};

void displaybook(struct book_library *book){
    printf("Title: %s\n",book->name);
    printf("Author: %s\n",book->author);
    printf("ISBN: %ld\n",book->isbn);
}

void add_books(struct book_library books[], char bookname[], char authorname[], long isbnnumber, int index){
    struct book_library newbook;
    strcpy(newbook.name,bookname);
    strcpy(newbook.author,authorname);
    newbook.isbn=isbnnumber;
    books[index]=newbook;
}

int main(){
    struct book_library bookarr[2];
    // struct person personarray[3];

    // storeperson(personarray,0,"John Doe",30,175.2);
    // storeperson(personarray,1,"George Bush",30,175.2);
    // storeperson(personarray,2,"Benjamin Franklin",30,175.2);

    // showperson(personarray);
  
    add_books(bookarr,"Charlie and the Chocolate Factory","Roald Dahl",116234234,0);
    add_books(bookarr,"Matilda","Roald Dahl",1123723423,1);

    for(int i=0;i<2;i++){
        displaybook(&bookarr[i]);
    }
    


    return 0;
}