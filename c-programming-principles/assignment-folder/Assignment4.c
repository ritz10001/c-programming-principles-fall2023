#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <ctype.h>
#include <string.h>

int main(){
    
    int bank_accounts[50];
    for(int i=0;i<50;i++){
        bank_accounts[i]=-1;
    }

    char choice;
    int random_opener;
    float initial_deposit;
    int acc_number;
    float deposit_amount;
    float withdraw_amount=0;
    int open_accounts_arr[]={};
    float interest_rate;

    printf("TRANSACTION TYPES\n");
    printf("O FOR OPENING AN ACCOUNT\n");
    printf("B FOR VIEWING BALANCES IN AN ACCOUNT\n");
    printf("D FOR DEPOSITING CASH IN AN ACCOUNT\n");
    printf("W FOR WITHDRAWING CASH FROM AN ACCOUNT\n");
    printf("C FOR CLOSING AN ACCOUNT\n");
    printf("I FOR ADDING AN INTEREST RATE TO ALL ACCOUNTS\n");
    printf("P FOR VIEWING ALL ACTIVE ACCOUNT NUMBERS AND BALANCES\n");
    printf("E FOR CLOSING ALL ACCOUNTS AND EXIT THE PROGRAM\n");

    while(1){
        char choice_check[1000];
        char choice;
        printf("Transaction Type?: ");
        scanf(" %s", choice_check);

        
        if(strlen(choice_check)==1){
            choice=choice_check[0];
        
            if(choice=='o' || choice=='O'){
                int result1;
                int result2;
                int bank_open_idx;
                printf("Provide the bank number you want to open (100-149): ");
                result1=scanf("%d", &bank_open_idx);
                if(bank_open_idx<100 || bank_open_idx>149){
                    printf("Please enter a valid bank account number!\n");
                }
                
                else if(result1==1){
                    if(bank_accounts[bank_open_idx-100]!=-1){
                        printf("An account with that number has already been opened!\n");
                    }
                    else{
                        printf("Initial deposit?: ");
                        result2=scanf("%f", &initial_deposit);
                        if(result2==1){
                            printf("\n");
                            if(initial_deposit<100){
                                printf("Your initial deposit needs to be of atleast a 100 dollars!");
                                printf("\n");
                            
                            }
                            else{
                                //random_opener=random_generator(&open_accounts_arr,50);
                                bank_accounts[bank_open_idx-100]=0;
                                bank_accounts[bank_open_idx-100]+=initial_deposit;

                                printf("Account number of newly opened account: %d", bank_open_idx);
                                printf("\n");
                            }
                        }
                        else{
                            printf("Please enter a valid value!\n");
                        }
                    }
                }
                else{
                    int check;
                    printf("Illegal characters!\n");
                    while ((check = getchar()) != '\n' && check != EOF);
                }

            }

            else if(choice=='B' || choice=='b'){
                int result;
                printf("Account number?: ");
                result=scanf("%d", &acc_number);
                printf("\n");
                if(result==1){
                    if(acc_number>=100 && acc_number<=149){
                        if(bank_accounts[acc_number-100]==-1){
                            printf("There is no bank account that is currently opened in that number!\n");
                        
                        }
                        else{
                            printf("Account number: %d\n", acc_number);
                            printf("Account Balance: %.2f\n", (float)bank_accounts[acc_number-100]);
                        }
                    }
                    else{
                        printf("Please enter a valid account number.\n");
                    }
            
                }
                else{
                    int check;
                    printf("Illegal characters!\n");
                    while ((check = getchar()) != '\n' && check != EOF);
                }
                


            }

            else if(choice=='D' || choice=='d'){
                int result;
                printf("Account number?: ");
                result=scanf("%d", &acc_number);
                printf("\n");
                if(result==1){
                    if(acc_number>=100 && acc_number<=149){

                        if(bank_accounts[acc_number-100]==-1){
                            printf("There is no bank account that is currently opened in that number!\n");       
                        }
                        else{
                            
                            printf("Amount?: ");
                            scanf("%f", &deposit_amount);
                            if(deposit_amount<0){
                                printf("Please enter a valid deposit amount! \n");
                            }
                            else{

                            
                                printf("\n");
                                bank_accounts[acc_number-100]+=deposit_amount;
                                
                                printf("Account number: %d\n", acc_number);
                                printf("Account Balance: %.2f\n", (float)bank_accounts[acc_number-100]);
                            }
                        }
                    }
                    else{
                        printf("Please enter a valid account number.\n");
                    }
                }
                else{
                    int check;
                    printf("Illegal characters!\n");
                    while ((check = getchar()) != '\n' && check != EOF);
                }

            }
            else if(choice=='W' || choice=='w'){
                int result;
                printf("Account number?: ");
                result=scanf("%d", &acc_number);
                printf("\n");
                if(result==1){
                    if(acc_number>=100 && acc_number<=149){

                        if(bank_accounts[acc_number-100]==-1){
                            printf("There is no bank account that is currently opened in that number!\n");
                        }
                        else{
                            printf("Amount?: ");
                            scanf("%f", &withdraw_amount);
                            printf("\n");
                            if(withdraw_amount<0){
                                printf("Please enter a valid withdraw amount! \n");
                            }
                            else{
                                if((bank_accounts[acc_number-100]-withdraw_amount<0)){
                                    printf("Insufficient funds! \n");
                                }
                                else{
                                    bank_accounts[acc_number-100]-=withdraw_amount;
                                    printf("Account number: %d\n", acc_number);
                                    printf("Account Balance: %.2f\n", (float)bank_accounts[acc_number-100]);
                                }
                    
                            }
                        }
                    }
                    else{
                        printf("Please enter a valid account number.\n");
                    }
                }
                else{
                    int check;
                    printf("Illegal characters!\n");
                    while ((check = getchar()) != '\n' && check != EOF);
                }
                
                


            }
            else if(choice=='C' || choice=='c'){
                int result;
                printf("Account number?: ");
                result=scanf("%d", &acc_number);
                printf("\n");
                if(result==1){
                    if(acc_number>=100 && acc_number<=149){
                        if(bank_accounts[acc_number-100]==-1){
                            printf("There is no bank account that is currently opened in that number!\n");
                        }
                        else{
                            bank_accounts[acc_number-100]=-1;
                            printf("Account has been closed successfully.\n");
                        }
                    }
                    else{
                        printf("Please enter a valid account number.\n");
                    }
                }   
                else{
                    
                    int check;
                    printf("Illegal characters!\n");
                    while ((check = getchar()) != '\n' && check != EOF);
                }
                

            }
            else if(choice=='P' || choice=='p'){
                int c=0;
                for(int i=0;i<50;i++){
                    if(bank_accounts[i]!=-1){
                        printf("Account Number: %d\n", i+100);
                        printf("Account Balance: %.2f\n", (float)bank_accounts[i]);
                        c++;
                    }
                }
                if(c==0){
                    printf("No accounts to show.\n");
                }
            }
            else if(choice=='I' || choice=='i'){
                int c=0;
                int result;
                printf("Interest Rate?: ");
                result=scanf("%f", &interest_rate);
                if(result==1){
                    for(int i=0;i<50;i++){
                        if(bank_accounts[i]!=-1){
                            bank_accounts[i]+=bank_accounts[i]*interest_rate/100;
                            c++;
                        }
                    }
                    if(c==0){
                        printf("There are no accounts that are currently open.\n");
                    }
                    else{
                        printf("Interest rate successfully applied to all open accounts.\n");
                    }
                    
                }
        
                else{
                    int check;
                    printf("Illegal characters!\n");
                    while ((check = getchar()) != '\n' && check != EOF);
                }
                
            
            }
            else if(choice=='E' || choice=='e'){
                for(int i=0;i<50;i++){
                    if(bank_accounts[i]!=-1){
                        bank_accounts[i]=-1;
                    }
                }
                printf("All accounts successfully closed.\n");
                return 0;
            }
            else{
                printf("Please enter a valid choice!\n");
            }
        }
        else{
            printf("Please enter a valid choice!\n");
        }

    }
    
    return 0;

}