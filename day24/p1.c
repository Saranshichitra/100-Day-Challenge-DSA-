#include <stdio.h>
#include <stdlib.h>

struct Node {                                            //defining structure of node                                          
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {                        //function to create a newnode                   
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertatend(struct Node* head, int value) {      //function to insert the node at the end
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}


struct node* deleteatposition(struct Node* head, int value){
    if(head == NULL){
        printf("List is empty");
        return head;
    }
    struct Node* temp = head;
    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        printf("Deletion not possible");
        return head;
    }
    struct Node* ptr = temp->next;
    temp->next = ptr->next;  
    free(ptr);
    return head;
}

void display(struct Node* head){                           //function to display the merged list
     while(head != NULL){
        printf("%d", head->data);
        head=head->next;
     }
}

int main() {
    int n, m, x, value;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertatend(head, x);
    }
    scanf("%d", &value);
    struct Node* deleted=deleteatposition(head, value);
    display(deleted);
    return 0;
}
