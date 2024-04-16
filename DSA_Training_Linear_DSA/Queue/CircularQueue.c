//Circular Queue using the Array in  C 


#include<stdio.h>
#include<stdlib.h>

#define max 10

int Queue[max],front=-1,rear=-1;


void enqueue(int value){
  if((rear == max-1 && front == 0)||(front==rear+1)){
    printf("Overflow");
  }
  else{
    if(front==-1){
        front = 0;
        rear = (rear+1)%max;
        Queue[rear] = value;
    }
    else{
        rear=(rear+1)%max;
        Queue[rear] = value;
    }
  }
}

int dequeue(){
   int deletion;
   if(front == -1){
    printf("Queue Empty");
    return -1;
   }
   else{
    deletion = Queue[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%max;
    }
    printf("%d",deletion);
   }
}

void display(){
    int i;
    if((front==-1)&&(rear==-1)){
        printf("\n Empty Queue\n");
    }
    printf("The Elements are in Queue:");
    for(i=front;i!=rear;i=(i+1)%max){
      printf("%d\n",Queue[i]); 
    }
    printf("%d",Queue[i]);
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    display();
}