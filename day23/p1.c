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

struct Node* merge(struct Node* l1, struct Node* l2){        //function to merge the lists
    struct Node *head = NULL, *temp = NULL;
    if(l1->data <= l2->data){
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    temp = head;
    while(l1 != NULL && l2 != NULL){
        if(l1->data <= l2->data){
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if(l1 != NULL)
        temp->next = l1;
    else
        temp->next = l2;
    return head;
}

void display(struct Node* head){                           //function to display the merged list
     while(head != NULL){
        printf("%d", head->data);
        head=head->next;
     }
}

int main() {
    int n, m, x;
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insertatend(l1, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l2 = insertatend(l2, x);
    }
    struct Node* merged=merge(l1, l2);
    display(merged);
    return 0;
}
