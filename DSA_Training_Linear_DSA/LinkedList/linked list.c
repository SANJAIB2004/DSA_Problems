#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head = NULL;
void insertion(struct node ** head,int data){

    struct node *newnode = (struct node*)malloc (sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head == NULL){
        *head = newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}
void display(struct node *head){
    struct node *temp =head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    }
int main(){
        int n,data;
        printf("Enter the no.of.nodes:");
        scanf("%d",&n);
        printf("enter the data");
        for(int i=0;i<n;i++){
            scanf("%d",&data);
            insertion(&head,data);
        }
        display(head);
        return 0;
}





