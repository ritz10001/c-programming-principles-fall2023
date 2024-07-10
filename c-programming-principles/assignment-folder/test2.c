#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Product{
    char product_name[50];
    int product_id;
    float product_price;
    int product_quantity;
    int is_added;


};

void addProduct(struct Product inventory[], int *numProducts, char name[], int productID, float price, int quantity);
void displayProduct(struct Product *product);
void searchByProductID(struct Product inventory[], int *numProducts, int productID);
void firefunction(struct Product inventory[], int *numProducts);
void addProductInfo(struct Product inventory[], int *numProducts);
void flushInput();



void addProduct(struct Product inventory[], int *numProducts, char name[], int productID, float price, int quantity){
    if(*numProducts>50){
        printf("Inventory is full! Maximum limit of 50 products has been reached!\n");
        return;
    }
    else{
        strncpy(inventory[*numProducts].product_name, name, sizeof(inventory->product_name));
        inventory[*numProducts].product_id = productID;
        inventory[*numProducts].product_price = price;
        inventory[*numProducts].product_quantity = quantity;
        inventory[*numProducts].is_added=1;
        printf("Product has been added into the inventory!\n");
        (*numProducts)++;
        return;
    }

}

void displayProduct(struct Product *product){
    printf("Inventory: \n");
    printf("Name \t\t ");
    printf("Product ID \t ");
    printf("Price \t\t");
    printf("Quantity");
    printf("\n");


    for(int i=0;i<50;i++){
        if(product[i].is_added==1){
            printf("%s", product[i].product_name);
            printf(" \t\t ");
            printf("%d", product[i].product_id);
            printf("\t\t ");
            printf("%f", product[i].product_price);
            printf(" \t");
            printf("%d", product[i].product_quantity);
            printf("\n");
        }
    }
}

void searchByProductID(struct Product inventory[], int *numProducts, int productID){
    for(int i=0;i<50;i++){
        if(inventory[i].product_id==productID){
            printf("Inventory: \n");
            printf("Name \t\t ");
            printf("Product ID \t ");
            printf("Price \t\t");
            printf("Quantity");
            printf("\n");
            printf("%s", inventory[i].product_name);
            printf(" \t\t ");
            printf("%d", inventory[i].product_id);
            printf("\t\t ");
            printf("%f", inventory[i].product_price);
            printf(" \t");
            printf("%d", inventory[i].product_quantity);
            printf("\n");
            return;
        }
    }
    printf("Product Number %d has not been found. Please make sure it exists within the inventory! \n", inventory[*numProducts].product_id);
}

void addProductInfo(struct Product inventory[], int *numProducts){

    char product_name[50];
    int product_ID;
    float product_price;
    int product_quantity;

    printf("Enter the product name: ");
    int res1 = scanf(" %s", product_name);
    flushInput();
    printf("\n");

    printf("Enter the product ID: ");
    int res2 = scanf(" %d", &product_ID);
    flushInput();
    printf("\n");

    printf("Enter the product price: ");
    int res3 = scanf(" %f", &product_price);
    flushInput();
    printf("\n");
    
    printf("Enter the product quantity: ");
    int res4 = scanf(" %d", &product_quantity);
    flushInput();
    printf("\n");

    if(res1!=1 || res2!=1 || res3!=1 || res4!=1){
        printf("You have entered some form of invalid information!\n");
        return;
    }
    else{
        addProduct(inventory,numProducts,product_name,product_ID,product_price,product_quantity);
    }


}

void firefunction(struct Product inventory[], int *numProducts){
    printf("Press 1 to add a new product\n");
    printf("Press 2 to display the whole inventory\n");
    printf("Press 3 to search a product based on its ID\n");
    printf("Press 0 to exit\n");

    int choice;
    while(true){
        int result = scanf(" %d", &choice);
        flushInput();
        if(result!=1){
            printf("Invalid choice! Try again!");
            break;
        }
        else{
            switch(choice){
                case 1:
                    addProductInfo(inventory,numProducts);
                    break;
                case 2:
                    displayProduct(inventory);
                    break;
                case 3:
                    int productID;
                    printf("Enter an ID\n");
                    int res = scanf("%d", &productID);
                    if(res!=1){
                        printf("Please enter a valid ID!\n");
                        firefunction(inventory,numProducts);
                    }
                    else{
                        searchByProductID(inventory, numProducts, productID);
                    } 
                case 0:
                    return;
                    break;
                default:
                    break;  
            }
        }
        firefunction(inventory,numProducts);

    }
}

void flushInput(){
    int c;
    while((c = getchar()) != '\n' && c != EOF) ;
}



int main(){

    struct Product inventory[50];
    int *numProducts = (int *)malloc(sizeof(int));
    *numProducts = 0;

    
    firefunction(inventory, numProducts);


    return 0;
}