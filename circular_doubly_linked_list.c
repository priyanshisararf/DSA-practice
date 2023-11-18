#include<stdio.h>
struct node{
    struct node*next,*prev;
    int data;
};
int n;
struct node *nw,*head,*tail,*temp,*temp1,*temp2;
void main(){
    int ch;
    nw=(struct node*)malloc(sizeof(struct node));
    nw->data=0;
    nw->next=head;
    nw->prev=tail;
    head=nw;
    tail=nw;
    creation();
    do{
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
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
void creation(){
    int i,item;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter item: ");
        scanf("%d",&item);
        if(head->data==0)
        head->data=item;
        else{
        nw=(struct node*)malloc(sizeof(struct node));
        nw->data=item;
        nw->next=head;
        tail->next=nw;
        nw->prev=tail;
        head->prev=nw;
        tail=nw;
        }
    }
}
void insertion(){
    int i,pos,item;
    printf("Enter item: ");
    scanf("%d",&item);
    printf("1. Beginning\n2. Middle\n3. End\n");
    printf("Enter choice: ");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1:
        nw=(struct node*)malloc(sizeof(struct node));
        nw->data=item;
        nw->next=head;
        nw->prev=tail;
        tail->next=nw;
        head->prev=nw;
        head=nw;
        break;
        case 2:
        nw=(struct node*)malloc(sizeof(struct node));
        nw->data=item;
        printf("Enter position: ");
        scanf("%d",&pos);
        temp=head;
        for(i=0;i<pos-2;i++)
        temp=temp->next;
        temp1=temp->next;
        nw->next=temp1;
        nw->prev=temp;
        temp->next=nw;
        temp1->prev=nw;
        break;
        case 3:
        nw=(struct node*)malloc(sizeof(struct node));
        nw->data=item;
        nw->next=head;
        nw->prev=tail;
        tail->next=nw;
        head->prev=nw;
        tail=nw;
        break;
    }
}
void deletion(){
    int i,pos;
    printf("1. Beginning\n2. Middle\n3. End\n");
    printf("Enter choice: ");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1:
        temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
        break;
        case 2:
        printf("Enter position: ");
        scanf("%d",&pos);
        temp=head;
        for(i=0;i<pos-2;i++)
        temp=temp->next;
        temp1=temp->next;
        temp2=temp1->next;
        temp->next=temp2;
        temp2->prev=temp;
        temp1->next=NULL;
        temp1->prev=NULL;
        free(temp1);
        break;
        case 3:
        temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
        break;
    }
}
void display(){
    if(head->data==0)
    printf("List empty");
    else{
        temp=head;
        while(temp->next!=head){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}