//Creating the implementation of queue in the linkedlist using C Language 

#include<stdio.h>
#include<stdlib.h>

// Struct definition in this part there is no memory allocated in this phase 
//only during the malloc() the memory allocated.

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = newNode;
        rear->next = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}


void dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue is Empty/n");
    }
    else{
        struct node * temp = front;
        front = front->next;
        printf("The Deleted node is %d",temp->data);
        free(temp);
    }
}

void display(){
 if(front == NULL && rear == NULL){
   printf("Queue is Empty\n");
 }

 else{
    struct node *temp =front;
   //we can also print use with the rear instead of NULL but we want to add the printf("%d",temp->data) 
   //below the loop. 
//    while(temp!=rear){
//     printf("Available Node is %d\n",temp->data);
//         temp=temp->next;
//    }
//    printf("Available Node is %d\n",temp->data);

    while(temp!=NULL){
        printf("Available Node is %d\n",temp->data);
        temp=temp->next;
    }
  }
}

 

int main(){
    
    int n,data;
    printf("Enter the number of nodes you want to insert in the queue\n");
    scanf("%d",&n);
    printf("Enter the data you want to insert in the queue\n");

    for(int i =0;i<n;i++){
        scanf("%d",&data);
        enqueue(data);
    }

    display();

    dequeue();
   
    return 0;
}


