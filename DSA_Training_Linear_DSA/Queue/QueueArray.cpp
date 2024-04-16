// cpp program to insert, delete elements in queue using array
#include<iostream>

#define size 50 // size of the queue using macro

using namespace std;

// class for queue using array
class Queue
{
private:
    int A[50];
    int front;  // starting index
    int rear;   // ending index

public:
    Queue()
    {
        front = rear = -1;
    }
    void enqueue(int x);
    int dequeue();

    void Display();

    bool isEmpty();
    bool isFull();
};

//implement the above functions of the above class using array

// enqueue - insert at end
void Queue :: enqueue(int x)
{
    if(isFull())
        return ;
    
    if(isEmpty())
    {
        front++, rear++;

        A[rear] = x;
    }
    else
    {
        rear++;

        A[rear] = x;
    }
}

// dequeue - delete at front
int Queue :: dequeue()
{
    int x;

    if(isEmpty())
        return -1;
    else
    {
        if(front == 0 && rear == 0)
        {
            x = A[front];

            front = rear = -1;
        }
        else
        {
            x = A[front];

            front++;
        }
    }

    return x;
}

bool Queue :: isEmpty()
{
    if(front == -1 && rear == -1)
        return true;
    
    return false;
}

bool Queue :: isFull()
{
    if(rear+1 >= size)
        return true;
    
    return false;
}

void Queue :: Display()
{
    int i;

    cout<<"Queue is : "<<endl;

    for(i=front;i<=rear;i++)
        cout<<A[i]<<" ";

    cout<<endl;
}

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.Display();

    cout<<"\nDelete element : "<<q.dequeue()<<endl;

    q.Display();
}