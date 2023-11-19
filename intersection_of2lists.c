#include<stdio.h>
struct node{
    int data;
    struct node* next;
};
struct node *nw1,*nw2,*nw,*head1,*head2,*head,*tail1,*tail2,*tail,*temp,*temp1,*temp2;
void creationL1();
void creationL2();
void intersection();
void displayL1();
void displayL2();
void displayL3();
void main(){
    nw=(struct node*)malloc(sizeof(struct node));
    nw->data=0;
    nw->next=NULL;
    head=nw;
    tail=nw;
    nw1=(struct node*)malloc(sizeof(struct node));
    nw1->data=0;
    nw1->next=NULL;
    head1=nw1;
    tail1=nw1;
    nw2=(struct node*)malloc(sizeof(struct node));
    nw2->data=0;
    nw2->next=NULL;
    head2=nw2;
    tail2=nw2;
    creationL1();
    creationL2();
    displayL1();
    displayL2();
    intersection();
    displayL3();
}
void creationL1(){
    int n,i;
    printf("Enter number of elements in List 1: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int a;
        printf("Enter element: ");
        scanf("%d",&a);
        if(head1->data==0)
        head1->data=a;
        else{
            nw1=(struct node*)malloc(sizeof(struct node));
            nw1->data=a;
            nw1->next=NULL;
            tail1->next=nw1;
            tail1=nw1;
        }
    }
}
void creationL2(){
    int n,i;
    printf("Enter number of elements in List 2: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int a;
        printf("Enter element: ");
        scanf("%d",&a);
        if(head2->data==0)
        head2->data=a;
        else{
            nw2=(struct node*)malloc(sizeof(struct node));
            nw2->data=a;
            nw2->next=NULL;
            tail2->next=nw2;
            tail2=nw2;
        }
    }
}
void intersection(){
    temp1=head1;
    while(temp1!=NULL){
        temp2=head2;
        while(temp2!=NULL){
        if(temp1->data==temp2->data){
            if(head->data==0)
            head->data=temp1->data;
            else{
                nw=(struct node*)malloc(sizeof(struct node));
                nw->data=temp1->data;
                nw->next=NULL;
                tail->next=nw;
                tail=nw;
            }
        }
        temp2=temp2->next;
    } 
    temp1=temp1->next;
}}
void displayL1(){
    if(head1->data==0)
    printf("EMPTY");
    else{
        temp1=head1;
        while(temp1!=NULL){
            printf("%d\t",temp1->data);
            temp1=temp1->next;
        }
    }
    printf("\n");
}
void displayL2(){
    if(head2->data==0)
    printf("EMPTY");
    else{
        temp2=head2;
        while(temp2!=NULL){
            printf("%d\t",temp2->data);
            temp2=temp2->next;
        }
    }
    printf("\n");
}
void displayL3(){
    if(head->data==0)
    printf("EMPTY");
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}