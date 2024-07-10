#include<stdio.h>


struct Node{
    char data;
    struct Node *next;         //data|next -> data|next
};

void push(struct Node **head_ref, char new_data){
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node)); 

    //inserting data to new node
    new_node->data=new_data;
    //make the new node point to the head node
    new_node->next=(*head_ref);
    //make the new node as the head node
    (*head_ref)=new_node;
}

int main(){
    return 0;
}