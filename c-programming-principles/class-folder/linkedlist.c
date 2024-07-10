#include<stdio.h>
#include<stdlib.h>


struct node* add_node(int data);
void add_to_list(struct node **headnode, int data);
void print_nodes(struct node *head);

struct node{
    int value;
    struct node *next; //points to another struct point, and the next *y subsequently points to another struct
    //this is a linked list end each struct point is a node
    //a node structure will contain some data and a pointer that will point to the next node in the list
};
//what if we wanted to point y to another struct point?

struct node* add_node(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value=data;
    new_node->next=NULL;
    return new_node;

    
}

void add_to_list(struct node **headnode, int data){
    struct node *newnode = add_node(data);
    if(*headnode==NULL){ //checking if headnode is ACTUALLY the headnode
        *headnode=newnode;
    }
    else{
        struct node *currentnode = *headnode;
        while(currentnode->next!=NULL){
            currentnode=currentnode->next;
        }
        currentnode->next=newnode;

    }

    
}

void print_nodes(struct node *head){
    if(head->next==NULL){
        printf("%d -> ", head->value);
    }
    else{
        while(head->next!=NULL){
            printf("%d -> ", head->value);
            head=head->next;
        }
        printf("%d ", head->value);
    }
}

int main(){
    struct node *first = NULL;
    // struct node *second = NULL;
    // struct node *third = NULL;
    // struct node *fourth = NULL;
    // struct node *fifth = NULL;
    
    //steps: 1) Allocate memory for node. 2) 
    //2) Store data in the node
    //(*new_node).value=10;
    //OR
    //first=NULL;
    
    // add_node(1);
    // add_node(2);
    // add_node(3);
    // add_node(4);
    // add_node(5);

    //print_nodes(first);

    
    add_to_list(&first,1);
    add_to_list(&first,2);
    add_to_list(&first,3);
    add_to_list(&first,4);
    add_to_list(&first,5);

    print_nodes(first);
    

    return 0;
}