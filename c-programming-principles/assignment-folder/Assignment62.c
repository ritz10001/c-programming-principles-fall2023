#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

// int programKey=1;
// int structSetup=0;

typedef struct {
    int room_number;
    int status;
    int room_type;
    char username[20];
    char lastname[30];
    char email[50];
    char address[100];
    char telephone_number[13];
    char check_in_date[15];
    char check_out_date[15];
} HotelRoom;



void initialSetup(HotelRoom*);
void bookRoom(HotelRoom*); //same as struct Room *rooms = struct Room*
void viewCustomerDetails(HotelRoom*);
void editCustomerDetails(HotelRoom*);
void checkOut(HotelRoom*, int roomNumber);
void viewReport(HotelRoom*);
//bool checkIfRoomEmpty(int roomNumber, HotelRoom*);
void programController(HotelRoom*, int*, int*);
void firefunction(HotelRoom*, int*, int*);
void flushInput();


void firefunction(HotelRoom *rooms, int *programKey, int *structSetup){
    char choice;
    while(true) {
        printf("\n");
        printf("Book a room (B or b)\n");
        printf("View customer details (V or v)\n");
        printf("Edit customer details (E or e)\n");
        printf("Check-out and print bill (C or c)\n");
        printf("View room report (A or a)\n");
        printf("Exit program (X or x)\n");

        int result = scanf(" %c", &choice);
        flushInput();
        if(result==0){
            printf("Invalid Input!\n");
        } 
        else{
            break;
        }
    }

    switch(tolower(choice)){
        case 'b':
            bookRoom(rooms);
            break;
        case 'v':
            viewCustomerDetails(rooms);
            break;
        case 'a':
            viewReport(rooms);
            break;
        case 'e':
            editCustomerDetails(rooms);
            break;
        case 'x':
            *programKey=0;
            programController(rooms, programKey, structSetup);
            break;
    }

}

void initialSetup(HotelRoom *rooms){
    for(int i=0;i<20;i++){
        int temp = i;
        rooms[i].room_number=temp+1;
        rooms[i].status=0;
        if(i<10){
            rooms[i].room_type=0;
        }
        else{
            rooms[i].room_type=1;
        }
    }
}

void bookRoom(HotelRoom *rooms){
    int roomNumber;
    while(true){
        printf("\n");
        printf("Enter the roomnumber you want to book: ");
        int result = scanf(" %d", &roomNumber);
        flushInput();
        printf("\n");

        if(result==0 || roomNumber>20 || roomNumber<=0){
            printf("Invalid Input!\n");
        }
        else{
            break;
        }
    }
    
    if(rooms[roomNumber-1].status==1){
        printf("Sorry, that room is already booked!\n");
    }
    else{
        char username[20], lastname[30], email[50], address[100];
        char telephone_number[12], check_in_date[15], check_out_date[15];

        int usernameCheck=0, lastnameCheck=0, emailCheck=0, addressCheck=0;
        int telephoneCheck=0, checkinCheck=0, checkoutCheck=0;

        while(true){
            if(usernameCheck==0){
                printf("Enter the username: ");
                int result1 = scanf(" %s", username);
                flushInput();
                printf("\n");

                if(result1==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].username,username,sizeof(rooms->username));
                    rooms[roomNumber-1].username[sizeof(rooms->username)-1] = '\0';
                    usernameCheck=1;
                }
            }
            if(lastnameCheck==0){
                printf("Enter the lastname: ");
                int result2 = scanf(" %s", lastname);
                flushInput();
                printf("\n");

                if(result2==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].lastname,lastname,sizeof(rooms->lastname));
                    rooms[roomNumber-1].lastname[sizeof(rooms->lastname)-1] = '\0';
                    lastnameCheck=1;
                }
            }
            if(emailCheck==0){
                printf("Enter the email address: ");
                int result3 = scanf(" %s", email);
                flushInput();
                printf("\n");

                if(result3==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].email,email,sizeof(rooms->email));
                    rooms[roomNumber-1].email[sizeof(rooms->email)-1] = '\0';
                    emailCheck=1;
                }
            }
            if(addressCheck==0){
                printf("Enter the physical address: ");
                int result4 = scanf(" %s", address);
                flushInput();
                printf("\n");

                if(result4==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].address,address,sizeof(rooms->address));
                    rooms[roomNumber-1].address[sizeof(rooms->address)-1] = '\0';
                    addressCheck=1;
                }
            }
            if(telephoneCheck==0){
                printf("Enter the telephone number: ");
                int result5 = scanf(" %s", telephone_number);
                flushInput();
                printf("\n");

                if(result5==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].telephone_number,telephone_number,sizeof(rooms->telephone_number));
                    rooms[roomNumber-1].telephone_number[sizeof(rooms->telephone_number)-1] = '\0';
                    telephoneCheck=1;
                }
            }
            if(checkinCheck==0){
                printf("Enter the check in date: ");
                int result6 = scanf(" %s", check_in_date);
                flushInput();
                printf("\n");

                if(result6==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].check_in_date,check_in_date,sizeof(rooms->check_in_date));
                    rooms[roomNumber-1].check_in_date[sizeof(rooms->check_in_date)-1] = '\0';
                    checkinCheck=1;
                }
            }
            if(checkoutCheck==0){
                printf("Enter the (MONTH) check out date: ");
                int result7 = scanf(" %s", check_out_date);
                flushInput();
                printf("\n");

                if(result7==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].check_out_date,check_out_date,sizeof(rooms->check_out_date));
                    rooms[roomNumber-1].check_out_date[sizeof(rooms->check_out_date)-1] = '\0';
                    checkoutCheck=1;
                }
            }
            break;
        }
    
        rooms[roomNumber-1].room_number = roomNumber;
        rooms[roomNumber-1].status = 1;
        rooms[roomNumber-1].room_type = roomNumber<=10 ? 0 : 1;
        printf("Room Number %d has been booked successfully.\n",roomNumber);
    }
    
}

void viewCustomerDetails(HotelRoom *rooms){
    printf("Enter the room number: ");
    int roomNum;
    while(true){
        int res = scanf(" %d", &roomNum);
        flushInput();
        if(res==0 || roomNum>20 || roomNum<=0){
            printf("Invalid Input!\n");
        }
        else{
            if(rooms[roomNum-1].status==0){
                printf("Room is vacant at the moment!\n");
                return;
            }
            else{
                break;
            }
        }
    }
    
    printf("\n");
    printf("****************Customer Details**************** \n");
    printf("\n");
    printf("Room Number: %d\n", rooms[roomNum-1].room_number);
    printf("Room Type: %s\n", rooms[roomNum-1].room_type==0 ? "Normal" : "Deluxe");
    printf("First Name: %s\n", rooms[roomNum-1].username);
    printf("Last Name: %s\n", rooms[roomNum-1].lastname);
    printf("Email Address: %s\n", rooms[roomNum-1].email);
    printf("Physical Address: %s\n", rooms[roomNum-1].address);
    printf("Telephone Number: %s\n", rooms[roomNum-1].telephone_number);
    printf("Check in Date: %s\n", rooms[roomNum-1].check_in_date);
    printf("Check out Date: %s\n", rooms[roomNum-1].check_out_date);

}
void viewReport(HotelRoom *rooms){
    printf("****************Room Report****************");
    printf("\n\n");
    printf("Room Number\tStatus\t\tFirst Name\tLast Name");
    printf("\n\n");
    for(int i=0;i<20;i++){
        printf("%d", rooms[i].room_number);
        printf("\t\t");
        printf(rooms[i].status==1 ? "Booked":"Vacant");
        printf("\t\t");
        printf("%s", rooms[i].status==0 ? "":rooms[i].username);
        printf("\t\t");
        printf("%s", rooms[i].status==0 ? "":rooms[i].lastname);
        printf("\n");
        
    }
    

}

void editCustomerDetails(HotelRoom *rooms){
    printf("Enter the room number: ");
    int roomNumber;
    char username[20], lastname[30], email[50], address[100];
    char telephone_number[13], check_in_date[15], check_out_date[15];
    while(true){
        int res = scanf(" %d", &roomNumber);
        flushInput();
        if(res==0 || roomNumber>20 || roomNumber<=0){
            printf("Invalid Input!\n");
        }
        else{
            if(rooms[roomNumber-1].status==0){
                printf("Room is vacant at the moment!\n");
                return;
            }
            else{
                break;
            }
        }
    }
    while(true){
        printf("\nWhat do you want to edit?: 1 for first name, 2 for last name, 3 for email, 4 for address, 5 for telephone, 6 for check in, 7 for check out, any other key to exit.\n");
        int choice;
        int res = scanf(" %d", &choice);
        flushInput();
        if(res==0 || (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6 && choice!=7)){
            break;
        }
        else{
            if(choice==1){
                printf("Enter the new username: ");
                int result1 = scanf(" %s", username);
                flushInput();
                printf("\n");

                if(result1==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].username,username,sizeof(rooms->username));
                    rooms[roomNumber-1].username[sizeof(rooms->username)-1] = '\0';
                }
            }
            else if(choice==2){
                printf("Enter the new lastname: ");
                int result2 = scanf(" %s", lastname);
                flushInput();
                printf("\n");

                if(result2==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].lastname,lastname,sizeof(rooms->lastname));
                    rooms[roomNumber-1].lastname[sizeof(rooms->lastname)-1] = '\0';
                }
            }
            else if(choice==3){
                printf("Enter the email address: ");
                int result3 = scanf(" %s", email);
                flushInput();
                printf("\n");

                if(result3==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].email,email,sizeof(rooms->email));
                    rooms[roomNumber-1].email[sizeof(rooms->email)-1] = '\0';
                }
            }
            else if(choice==4){
                printf("Enter the physical address: ");
                int result4 = scanf(" %s", address);
                flushInput();
                printf("\n");

                if(result4==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].address,address,sizeof(rooms->address));
                    rooms[roomNumber-1].address[sizeof(rooms->address)-1] = '\0';
                }
            }
            else if(choice==5){
                printf("Enter the telephone number: ");
                int result5 = scanf(" %s", telephone_number);
                flushInput();
                printf("\n");

                if(result5==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].telephone_number,telephone_number,sizeof(rooms->telephone_number));
                    rooms[roomNumber-1].telephone_number[sizeof(rooms->telephone_number)-1] = '\0';
                }
            }
            else if(choice==6){
                printf("Enter the check in date: ");
                int result6 = scanf(" %s", check_in_date);
                flushInput();
                printf("\n");

                if(result6==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].check_in_date,check_in_date,sizeof(rooms->check_in_date));
                    rooms[roomNumber-1].check_in_date[sizeof(rooms->check_in_date)-1] = '\0';
                }
            }
            else if(choice==7){
                printf("Enter the check out date: ");
                int result6 = scanf(" %s", check_out_date);
                flushInput();
                printf("\n");

                if(result6==0){
                    printf("Invalid Input!\n");
                }
                else{
                    strncpy(rooms[roomNumber-1].check_out_date,check_in_date,sizeof(rooms->check_out_date));
                    rooms[roomNumber-1].check_out_date[sizeof(rooms->check_out_date)-1] = '\0';
                }
            }
        }


        
    }
}

void programController(HotelRoom *rooms, int *programKey, int *structSetup){
    if(*structSetup==0){
        *structSetup=1;
        initialSetup(rooms);
        firefunction(rooms, programKey, structSetup);
    }
    while(*programKey==1){
        firefunction(rooms, programKey, structSetup);
    }
}
void flushInput(){
    int c;
    while((c = getchar()) != '\n' && c != EOF)
    /* discard */ ;
}


int main(){
    HotelRoom rooms[20];
    
    int *programKey = (int *)malloc(sizeof(int));
    int *structSetup = (int *)malloc(sizeof(int));

    *programKey = 1;
    *structSetup = 0;

    programController(rooms,programKey,structSetup);
    
    return 0;
}