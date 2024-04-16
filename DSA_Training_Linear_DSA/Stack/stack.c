#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Function to create a new node with given data
StackNode* newNode(int data) {
    StackNode* stackNode = (StackNode*) malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}



// Function to check if the stack is empty
int isEmpty(StackNode *root) {
    return !root;
}

// Function to push an item to stack
void push(StackNode** root, int data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}


// Function to pop an item from stack
int pop(StackNode** root) {
    if (isEmpty(*root))
        return INT_MIN;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to return the top from stack without removing it
int peek(StackNode* root) {
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main() {
    StackNode* root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    printf("%d popped from stack\n", pop(&root));
    printf("Top element is %d\n", peek(root));
    return 0;
}
