#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct {
    int room_number;
    int status;
    int room_type;
    char username[20];
    char lastname[30];
    char email[50];
    char address[100];
    char telephone_number[13];
    char check_in_date_month[3];
    char check_in_date_day[3];
    char check_in_date_year[5];
    char check_out_date_month[3];
    char check_out_date_day[3];
    char check_out_date_year[5];
} HotelRoom;



void initialSetup(HotelRoom*);
void bookRoom(HotelRoom*); 
void viewCustomerDetails(HotelRoom*);
void editCustomerDetails(HotelRoom*);
void checkOutandPrintBill(HotelRoom*);
void viewReport(HotelRoom*);
void programController(HotelRoom*, int*, int*);
int isValidDate(int month, int day, int year);
int daysInMonth(int month, int year); 
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
        case 'c':
            checkOutandPrintBill(rooms);
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
        char telephone_number[12], check_in_date_month[3], check_in_date_day[3], check_in_date_year[5];
        char check_out_date_month[3], check_out_date_day[3], check_out_date_year[5];

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
                printf("Enter the (MONTH) check in date: ");
                int result6i = scanf(" %s", check_in_date_month);
                flushInput();
                printf("\n");

                printf("Enter the (DAY) check in date: ");
                int result6ii = scanf(" %s", check_in_date_day);
                flushInput();
                printf("\n");

                printf("Enter the (YEAR) check in date: ");
                int result6iii = scanf(" %s", check_in_date_year);
                flushInput();
                printf("\n");

                if(result6i==0 || result6ii==0 || result6iii==0){
                    checkinCheck=0;
                }
                else{
                    if(isValidDate(atoi(check_in_date_month),atoi(check_in_date_day),atoi(check_in_date_year))){
                        strncpy(rooms[roomNumber-1].check_in_date_month,check_in_date_month,sizeof(rooms->check_in_date_month));
                        rooms[roomNumber-1].check_in_date_month[sizeof(rooms->check_in_date_month)-1] = '\0';
                        strncpy(rooms[roomNumber-1].check_in_date_day,check_in_date_day,sizeof(rooms->check_in_date_day));
                        rooms[roomNumber-1].check_in_date_day[sizeof(rooms->check_in_date_day)-1] = '\0';
                        strncpy(rooms[roomNumber-1].check_in_date_year,check_in_date_year,sizeof(rooms->check_in_date_year));
                        rooms[roomNumber-1].check_in_date_year[sizeof(rooms->check_in_date_year)-1] = '\0';
                        checkinCheck=1;
                    }
                }
            }
            if(checkoutCheck==0){
                printf("Enter the (MONTH) check out date: ");
                int result7 = scanf(" %s", check_out_date_month);
                flushInput();
                printf("\n");

                printf("Enter the (DAY) check out date: ");
                int result7ii = scanf(" %s", check_out_date_day);
                flushInput();
                printf("\n");

                printf("Enter the (YEAR) check out date: ");
                int result7iii = scanf(" %s", check_out_date_year);
                flushInput();
                printf("\n");


                if(result7==0 || result7ii==0 || result7iii==0){
                    checkoutCheck=0;
                }
                else{
                    if(isValidDate(atoi(check_out_date_month),atoi(check_out_date_day),atoi(check_out_date_year))){
                        strncpy(rooms[roomNumber-1].check_out_date_month,check_out_date_month,sizeof(rooms->check_out_date_month));
                        rooms[roomNumber-1].check_out_date_month[sizeof(rooms->check_out_date_month)-1] = '\0';
                        strncpy(rooms[roomNumber-1].check_out_date_day,check_out_date_day,sizeof(rooms->check_out_date_day));
                        rooms[roomNumber-1].check_out_date_day[sizeof(rooms->check_out_date_day)-1] = '\0';
                        strncpy(rooms[roomNumber-1].check_out_date_year,check_out_date_year,sizeof(rooms->check_out_date_year));
                        rooms[roomNumber-1].check_out_date_year[sizeof(rooms->check_out_date_year)-1] = '\0';
                        checkoutCheck=1;
                    }
                }
            }
            int tempCheckInDay = atoi(rooms[roomNumber-1].check_in_date_day);
            int tempCheckInMonth = atoi(rooms[roomNumber-1].check_in_date_month);
            int tempCheckInYear = atoi(rooms[roomNumber-1].check_in_date_year);

            int tempCheckOutDay = atoi(rooms[roomNumber-1].check_out_date_day);
            int tempCheckOutMonth = atoi(rooms[roomNumber-1].check_out_date_month);
            int tempCheckOutYear = atoi(rooms[roomNumber-1].check_out_date_year);
            if(checkoutCheck==1 && checkinCheck==1){
                if((tempCheckOutMonth<tempCheckInMonth && tempCheckOutYear<=tempCheckInYear) || tempCheckOutYear<tempCheckInYear){
                    printf("Invalid Dates! Please try again!\n");
                    checkoutCheck=0;
                    checkinCheck=0;
                }
                else{
                    if((tempCheckOutDay<tempCheckInDay && tempCheckOutMonth<=tempCheckInMonth && tempCheckOutYear<=tempCheckInYear)){
                        printf("Invalid Dates! Please try again!\n");
                        checkoutCheck=0;
                        checkinCheck=0;
                    }
                    else{
                        break;
                    }
                    
                }
                
            }
            else{
                printf("Invalid Dates! Please try again!\n");
                checkoutCheck=0;
                checkinCheck=0;
            }
            
        }
    
        rooms[roomNumber-1].room_number = roomNumber;
        rooms[roomNumber-1].status = 1;
        rooms[roomNumber-1].room_type = roomNumber<=10 ? 0 : 1;
        printf("Room Number %d has been booked successfully.\n",roomNumber);
    }
    
}

void viewCustomerDetails(HotelRoom *rooms){
    int roomNum;
    while(true){
        printf("Enter the room number: ");
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
    printf("Check in Date: %s-%s-%s\n", rooms[roomNum-1].check_in_date_month,rooms[roomNum-1].check_in_date_day,rooms[roomNum-1].check_in_date_year);
    printf("Check out Date: %s-%s-%s\n", rooms[roomNum-1].check_out_date_month,rooms[roomNum-1].check_out_date_day,rooms[roomNum-1].check_out_date_year);

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
        if(rooms[i].status==1){
            printf("\t\t");
            printf("%s", rooms[i].status==0 ? "":rooms[i].username);
            printf("\t\t");
            printf("%s", rooms[i].status==0 ? "":rooms[i].lastname);
            printf("\n");
        }
        else{
            printf("\t\t");
            printf("\t\t");
            printf("\n");
        }
        
        
    }
    

}

void editCustomerDetails(HotelRoom *rooms){
    printf("Enter the room number: ");
    int roomNumber;
    int cycles = 0;
    char username[20], lastname[30], email[50], address[100];
    char telephone_number[13], check_in_date_month[3], check_in_date_day[3], check_in_date_year[5];
    char check_out_date_month[3], check_out_date_day[3], check_out_date_year[5];
    int checkinCheck=0, checkoutCheck=0;
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
                printf("Enter the (MONTH) check in date: ");
                int result6i = scanf(" %s", check_in_date_month);
                flushInput();
                printf("\n");

                printf("Enter the (DAY) check in date: ");
                int result6ii = scanf(" %s", check_in_date_day);
                flushInput();
                printf("\n");

                printf("Enter the (YEAR) check in date: ");
                int result6iii = scanf(" %s", check_in_date_year);
                flushInput();
                printf("\n");

                if(result6i==0 || result6ii==0 || result6iii==0){
                    checkinCheck=0;
                }
                else{
                    if(isValidDate(atoi(check_in_date_month),atoi(check_in_date_day),atoi(check_in_date_year))){
                        strncpy(rooms[roomNumber-1].check_in_date_month,check_in_date_month,sizeof(rooms->check_in_date_month));
                        rooms[roomNumber-1].check_in_date_month[sizeof(rooms->check_in_date_month)-1] = '\0';
                        strncpy(rooms[roomNumber-1].check_in_date_day,check_in_date_day,sizeof(rooms->check_in_date_day));
                        rooms[roomNumber-1].check_in_date_day[sizeof(rooms->check_in_date_day)-1] = '\0';
                        strncpy(rooms[roomNumber-1].check_in_date_year,check_in_date_year,sizeof(rooms->check_in_date_year));
                        rooms[roomNumber-1].check_in_date_year[sizeof(rooms->check_in_date_year)-1] = '\0';
                        checkinCheck=1;
                    }
                }
            }
            else if(choice==7){
                printf("Enter the (MONTH) check out date: ");
                int result7 = scanf(" %s", check_out_date_month);
                flushInput();
                printf("\n");

                printf("Enter the (DAY) check out date: ");
                int result7ii = scanf(" %s", check_out_date_day);
                flushInput();
                printf("\n");

                printf("Enter the (YEAR) check out date: ");
                int result7iii = scanf(" %s", check_out_date_year);
                flushInput();
                printf("\n");


                if(result7==0 || result7ii==0 || result7iii==0){
                    checkoutCheck=0;
                }
                else{
                    if(isValidDate(atoi(check_out_date_month),atoi(check_out_date_day),atoi(check_out_date_year))){
                        strncpy(rooms[roomNumber-1].check_out_date_month,check_out_date_month,sizeof(rooms->check_out_date_month));
                        rooms[roomNumber-1].check_out_date_month[sizeof(rooms->check_out_date_month)-1] = '\0';
                        strncpy(rooms[roomNumber-1].check_out_date_day,check_out_date_day,sizeof(rooms->check_out_date_day));
                        rooms[roomNumber-1].check_out_date_day[sizeof(rooms->check_out_date_day)-1] = '\0';
                        strncpy(rooms[roomNumber-1].check_out_date_year,check_out_date_year,sizeof(rooms->check_out_date_year));
                        rooms[roomNumber-1].check_out_date_year[sizeof(rooms->check_out_date_year)-1] = '\0';
                        checkoutCheck=1;
                    }
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

int isValidDate(int month, int day, int year) {
    // Basic checks for valid month, day, and year ranges
    if (month<1 || month>12 || day<1 || day>31 || year<1000 || year>9999) {
        return 0; // Invalid date
    }

    // Additional checks for specific month-day combinations
    if((month==4 || month==6 || month==9 || month==11) && day>30) {
        return 0; // Invalid date for 30-day months
    } else if(month==2){
        // Check for February and leap years
        if((year%4==0 && year%100!=0)) {
            if(year%400==0 && day<=29){
                return 1; // Valid date for leap year February
            }
            
        } else if(day>28){
            return 0; // Invalid date for non-leap year February
        }
    }
    return 1; // Valid date
}

void checkOutandPrintBill(HotelRoom *rooms){
    int tempRoomNum;
    int rate = 50;
    int days = 0;
    int cycles = 0;

    

    while(true){
        
        printf("\n");
        printf("Enter the roomnumber: ");
        int result = scanf(" %d", &tempRoomNum);
        flushInput();
        printf("\n");

        if(tempRoomNum==0 || tempRoomNum>20 || tempRoomNum<=0){
            printf("Invalid Input!\n");
            return;
        }
        else if(rooms[tempRoomNum-1].status==0){
            printf("Room is vacant at the moment!\n");
            return;
        }
        else{
            break;
        }
    }
    int tempCheckInDay = atoi(rooms[tempRoomNum-1].check_in_date_day);
    int tempCheckInMonth = atoi(rooms[tempRoomNum-1].check_in_date_month);
    int tempCheckInYear = atoi(rooms[tempRoomNum-1].check_in_date_year);

    int tempCheckOutDay = atoi(rooms[tempRoomNum-1].check_out_date_day);
    int tempCheckOutMonth = atoi(rooms[tempRoomNum-1].check_out_date_month);
    int tempCheckOutYear = atoi(rooms[tempRoomNum-1].check_out_date_year);

    while (!(tempCheckInDay == atoi(rooms[tempRoomNum-1].check_out_date_day) &&
             tempCheckInMonth == atoi(rooms[tempRoomNum-1].check_out_date_month) &&
             tempCheckInYear == atoi(rooms[tempRoomNum-1].check_out_date_year))) {
        days++;
        tempCheckInDay+=1;
        if(cycles>1000){
            printf("An error occured while attempting to calculate your costs. This may have occured either due to invalid dates or attempts to break the code.\n");
            break;
        }
        cycles++;

        if(tempCheckInDay > daysInMonth(tempCheckInMonth, tempCheckInYear)) {
            tempCheckInDay = 1;
            tempCheckInMonth+=1;

            if(tempCheckInMonth>12){
                tempCheckInMonth = 1;
                tempCheckInYear+=1;
            }
        }
    }
    if(cycles>1000){
        return;
    }

    printf("\nYou have been successfully checked out. The total cost of stay: $%d\n", days*rate+50);

    rooms[tempRoomNum-1].status=0;

    
}   

int daysInMonth(int month, int year) {
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                return 29; // Leap year
            else
                return 28;
        default:
            return 31;
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