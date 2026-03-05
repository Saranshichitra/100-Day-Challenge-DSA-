#include <stdio.h>
#include <stdlib.h>
int *arr;
int top = -1;
int max;
void push(int value){
    if(top == max-1){
        printf("Overflow\n");
        return;
    }
    arr[++top] = value;
}

void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    printf("Deleted %d\n", arr[top--]);
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for(int i = top; i >= 0; i--){
        printf("%d\n", arr[i]);
    }
}

int main(){
    int n, value, choice;
    printf("Enter stack size: ");
    scanf("%d",&max);
    arr = (int*)malloc(max * sizeof(int));
    printf("How many values to insert initially: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&value);
        push(value);
    }
    while(1){
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter value: ");
            scanf("%d",&value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            free(arr);
            break;

        default:
            printf("Invalid input");
    }
}
    return 0;
}