#include <stdio.h>
#define MAX 100
int pq[MAX];
int size = 0;

void insert(int value){
    if(size == MAX){
        printf("Queue Overflow\n");
        return;
    }
    int i = size - 1;
    while(i >= 0 && pq[i] > value){
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = value;
    size++;
}
void delete(){
    if(size == 0){
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", pq[0]);
    for(int i = 1; i < size; i++){
        pq[i - 1] = pq[i];
    }
    size--;
}

void display(){
    if(size == 0){
        printf("Queue is empty\n");
        return;
    }

    for(int i = 0; i < size; i++){
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main(){
    int choice, value;
    while(1){
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
        }
        else if(choice == 2){
            delete();
        }
        else if(choice == 3){
            display();
        }
        else if(choice == 4){
            break;
        }
        else{
            printf("Invalid choice\n");
        }
    }
    return 0;
}