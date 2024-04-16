#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct stack {
    int arr[MAX_SIZE];
    int top;
};

void init(struct stack*);
void push(struct stack*, int);
void pop(struct stack*);
void display(struct stack);

int main() {
    struct stack s;
    init(&s);
    int a;
    int size;
    printf("Enter the no of elements \n");
    scanf("%d",&size);
     printf("Enter the elements to be pushed \n");
    for(int i =0;i<size;i++){
    scanf("%d",&a);
    push(&s,a);
    printf("\n");
    }
    display(s);
    
    pop(&s);
    
    display(s);
    
    return 0;
}

void init(struct stack* s) {
    s->top = -1;
}

void push(struct stack* s, int item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->arr[s->top] = item;
    }
}

void pop(struct stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        int popped = s->arr[s->top];
        s->top--;
        printf("%d\n", popped);
    }
}

void display(struct stack s) {
    if (s.top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = s.top; i >= 0; i--) {
            printf("%d ", s.arr[i]);
        }
        printf("\n");
    }
}

