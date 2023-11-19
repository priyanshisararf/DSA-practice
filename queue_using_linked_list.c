#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node *nw,*front,*rear,*temp;
void main(){
    nw=(struct node*)malloc(sizeof(struct node));
    nw->data=0;
    nw->next=rear;
    rear=nw;
    front=nw;
    int ch;
    do{
        printf("\n1. INSERTION\n2. DELETION\n3. DISPLAY\n4. EXIT\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insertion();
            break;
            case 2:
            deletion();
            break;
            case 3:
            display();
            break;
        }
    }while(ch<4);
}
void insertion(){
    int item;
    printf("Enter item: ");
    scanf("%d",&item);
    if(front->data==0)
    front->data=item;
    else{
        nw=(struct node*)malloc(sizeof(struct node));
        nw->data=item;
        nw->next=NULL;
        rear->next=nw;
        rear=nw;
    }
}
void deletion(){
    if(front->data==0)
    printf("Queue is empty");
    else{
        temp=front;
        front=front->next;
        temp->next=NULL;
        free(temp);
    }
}
void display(){
    if(front->data==0)
    printf("Queue is empty");
    else{
        temp=front;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}