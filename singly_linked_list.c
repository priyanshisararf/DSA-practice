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
    nw->next=NULL;
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
    int i, item;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter item: ");
        scanf("%d",&item);
        if(head->data==0){
            head->data=item;
        }
        else{
            nw=(struct node*)malloc(sizeof(struct node));
            nw->data=item;
            nw->next=NULL;
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
        nw->next=head;
        head=nw;
        break;
        case 2:
        printf("Enter position: ");
        scanf("%d",&pos);
        nw=(struct node*)malloc(sizeof(struct node));
        nw->data=item;
        temp=head;
        for(i=0;i<pos-2;i++){
            temp=temp->next;
        }
        nw->next=temp->next;
        temp->next=nw;
        break;
        case 3:
        nw=(struct node*)malloc(sizeof(struct node));
        nw->data=item;
        nw->next=NULL;
        tail->next=nw;
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
        head=temp->next;
        temp->next=NULL;
        free(temp);
        break;
        case 2:
        printf("Enter position: ");
        scanf("%d",&pos);
        temp=head;
        for(i=0;i<pos-2;i++)
        temp=temp->next;
        temp1=temp->next;
        temp->next=temp1->next;
        temp1->next=NULL;
        free(temp1);
        break;
        case 3:
        temp=head;
        int c=0;
        while(temp->next!=NULL){
            temp=temp->next;
            c++;
        }
        temp=head;
        temp1=tail;
        for(i=0;i<c-1;i++)
        temp=temp->next;
        temp->next=NULL;
        tail=temp;
        free(temp1);
        break;
    }
}
void display(){
    if(head->data==0)
    printf("List Empty");
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}