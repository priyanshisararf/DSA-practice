#include<stdio.h>
struct node{
    struct node*next;
    int data;
};
int n;
struct node *nw,*head,*tail,*temp,*temp1;
void main(){
    int ch;
    nw=(struct node*)malloc(sizeof(struct node));
    nw->data=0;
    nw->next=head;
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
        tail->next=nw;
        nw->next=head;
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
        nw->next=temp->next;
        temp->next=nw;
        break;
        case 3:
        nw=(struct node*)malloc(sizeof(struct node));
        nw->data=item;
        tail->next=nw;
        nw->next=head;
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
        tail->next=temp->next;
        head=temp->next;
        temp->next=NULL;
        free(temp);
        break;
        case 2:

        break;
        case 3:
        temp=head;
        int c=0;
        while(temp->next!=head){
            c++;
            temp=temp->next;
        }
        temp=head;
        for(i=0;i<c-1;i++)
        temp=temp->next;
        temp1=tail;
        temp->next=head;
        tail=temp;
        temp1->next=NULL;
        free(temp1);
        break;
    }
}
void display(){
    if(head->data==0)
    printf("List Empty");
    else{
        temp=head;
        while(temp->next!=head){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}