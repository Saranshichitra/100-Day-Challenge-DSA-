#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head=NULL;
    struct node *tail=NULL;
    struct node *temp=head;
    int n, value;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &value);
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        if(temp == NULL){
            head=newnode;
        }
        temp->next=newnode;
        temp=newnode;
    struct node *t=head;
    while(t != NULL){
        printf("%d ", t->data);
        t=t->next;
    }
}
  return 0;
}
