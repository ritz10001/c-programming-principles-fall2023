#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

struct Room{
    int room_number;
    int status;
    int room_type;
    char username[20];
    char lastname[30];
    char email[50];
    char address[100];
    char telephone_number[12];
    char check_in_date[15];
    char check_out_date[15];
};

void bookRoom(struct Room *rooms, int roomType); //same as struct Room *rooms = struct Room*
void viewCustomerDetails(int roomNumber);
void editCustomerDetails(struct Room *rooms, int roomNumber);
void checkOut(struct Room *rooms, int roomNumber);
void viewReport(struct Room *roomlist[20]);
bool checkIfRoomEmpty(int roomNumber, int roomArray[20]);
void firefunction();


int room_array[20];
struct Room *roomslist[20];
int programKey=1;
void fire_function(){
    printf("Book a room (B or b)\n");
    printf("View customer details (V or v)\n");
    printf("Edit customer details (E or e)\n");
    printf("Check-out and print bill (C or c)\n");
    printf("View room report (A or a)\n");
    printf("Exit program (X or x)\n");

    

    char choice;
    scanf(" %c", &choice);

    switch(tolower(choice)){
        case 'b':
            int room_number;
            int status;
            int room_type;
            char username[20];
            char lastname[30];
            char email[50];
            char address[100];
            char telephone_number[12];
            char check_in_date[15];
            char check_out_date[15];
            printf("Enter a room number to book\n");
            scanf(" %d",&room_number);
            // printf("Enter the room type\n");
            // scanf(" %d", &room_type);
            printf("Enter your user name\n");
            scanf(" %s", username);
            printf("Enter your last name\n");
            scanf(" %s", lastname);
            printf("Enter your email address\n");
            scanf(" %s", email);
            printf("Enter your actual address\n");
            scanf(" %s", address);
            printf("Enter your telephone number\n");
            scanf(" %s", telephone_number);
            printf("Enter the check in date\n");
            scanf(" %s", check_in_date);
            printf("Enter the check out date\n");
            scanf(" %s", check_out_date);

            struct Room *room = (struct Room*)malloc(sizeof(struct Room));
            if (room == NULL) {
                printf("Error: Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }

            if(checkIfRoomEmpty(room_number,room_array)){
                room_array[room_number]=1;
                room->status=true;
                // room->room_number=room_number;
                strncpy(room->username,username,sizeof(room->username));
                strncpy(room->lastname,lastname,sizeof(room->lastname));
                strncpy(room->email,email),50;
                strncpy(room->address,address,100);
                strncpy(room->telephone_number,telephone_number,12);
                strncpy(room->check_in_date,check_in_date,15);
                strncpy(room->check_out_date,check_out_date,15);

                printf("THIS IS THE VALUE OF USERNAME %s", room->username);
                bookRoom(room,room_number);
                
            }
            else{
                break;
            }
            break;


        case 'v':
            int tempRoomNumber;
            printf("Please enter the room number you need the details for: ");
            scanf("%d", &tempRoomNumber);
            viewCustomerDetails(tempRoomNumber);
            break;
        // case 'e':
        //     editCustomerDetails();
        //     break;
        // case 'c':
        //     checkOut();
        //     break;
        case 'a':
            viewReport(roomslist);
            break;
        case 'x':
            programKey=0;
            main();
            break;
    }
}

void viewCustomerDetails(int roomNumber){
    if(room_array[roomNumber]==1){
        struct Room *tempRoom = (struct Room*)malloc(sizeof(struct Room));
        tempRoom = roomslist[roomNumber];
        printf("Details of the customer: \n");
        printf("Username: %s\n", tempRoom->username);
        printf("Last Name: %s\n", tempRoom->lastname);
        printf("Email Address: %s\n", tempRoom->email);
        printf("Physical Address: %s\n", tempRoom->address);
        printf("Telephone Number: %s\n", tempRoom->telephone_number);
        printf("Check-in Date: %s\n", tempRoom->check_in_date);
        printf("Check-out Date: %s\n", tempRoom->check_out_date);
        free(tempRoom);
    }
    else{
        printf("The room you selected is currently vacant!\n");
    }
    
}

void viewReport(struct Room *roomlist[]){
    printf("Room Report: \n");
    printf("Room Number \t Status \t First Name \t\t Last Name\n");
    for(int i=0;i<20;i++){
        if(roomslist[i]!=0){
            printf("%d",roomlist[i]->room_number);
            printf("\t");
            printf("%d",roomlist[i]->status);
            printf("\t  ");
            printf("%s",roomlist[i]->username);
            printf("\t\t ");
            printf("%s",roomlist[i]->lastname);
            printf("\t");
            printf("\n");
        }
        else{
            continue;
        }
        
    }

}


bool checkIfRoomEmpty(int roomNumber, int roomArray[20]){
    if(roomArray[roomNumber]!=1){
        return true;
    }
    else{
        return false;
    }
}

void bookRoom(struct Room *rooms, int roomNumber){
    rooms->room_type=roomNumber;
    int counter=0;
    while(room_array[counter]!=1){
        counter++;
    }
    roomslist[counter]=rooms;
    printf("The latest room has been booked in slot %d\n", counter);
    printf("The user name is %s\n", roomslist[counter]->username);
    free(rooms);

}

int main(){
    while(programKey==1){
        fire_function();
    }
    return 0;
}

