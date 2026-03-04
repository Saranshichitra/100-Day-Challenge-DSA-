#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int value){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

struct node* push(struct node* top, int value){
    struct node* newnode = createnode(value);
    newnode->next = top;
    return newnode;
}

struct node* pop(struct node* top){
    if(top == NULL){
        printf("Stack Underflow\n");
        return NULL;
    }
    struct node* temp = top;
    printf("Deleted: %d\n", temp->data);
    top = top->next;
    free(temp);
    return top;
}

void display(struct node* top){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    printf("TOP -> ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* top = NULL;
    int choice, value;
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter value: ");
            scanf("%d",&value);
            top = push(top,value);
            display(top);
            break;

        case 2:
            top = pop(top);
            display(top);
            break;

        case 3:
            display(top);
            break;

        default:
            printf("Invalid choice");
    }
    return 0;
}