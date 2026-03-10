#include<stdio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void push_front(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
        printf("Overflow\n");
    else if(front==-1)
        front=rear=0;
    else if(front==0)
        front=MAX-1;
    else
        front--;

    deque[front]=x;
}

void push_back(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
        printf("Overflow\n");
    else if(front==-1)
        front=rear=0;
    else if(rear==MAX-1)
        rear=0;
    else
        rear++;
    deque[rear]=x;
}

void display()
{
    int i=front;
    if(front==-1)
        printf("Deque empty\n");
    else
    {
        while(i!=rear)
        {
            printf("%d ",deque[i]);
            i=(i+1)%MAX;
        }
        printf("%d",deque[i]);
    }
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();
}