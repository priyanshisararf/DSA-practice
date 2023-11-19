#include<stdio.h>
struct node{
    int coeff,pow;
    struct node* next;
};
struct node *nw1,*nw2,*nw,*head1,*head2,*head,*tail1,*tail2,*tail,*temp,*temp1,*temp2;
void creationP1();
void creationP2();
void addition();
void displayP1();
void displayP2();
void displatP3();
void main(){
    nw=(struct node*)malloc(sizeof(struct node));
    nw->coeff=0;
    nw->pow=0;
    nw->next=NULL;
    head=nw;
    tail=nw;
    nw1=(struct node*)malloc(sizeof(struct node));
    nw1->coeff=0;
    nw->pow=0;
    nw1->next=NULL;
    head1=nw1;
    tail1=nw1;
    nw2=(struct node*)malloc(sizeof(struct node));
    nw2->coeff=0;
    nw2->pow=0;
    nw2->next=NULL;
    head2=nw2;
    tail2=nw2;
    creationP1();
    creationP2();
    displayP1();
    displayP2();
    addition();
    displayP3();
}
void creationP1(){
    int n,i,c,p;
    printf("Enter number of terms of polynomial 1: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter coefficient of term %d:",i+1);
        scanf("%d",&c);
        printf("Enter power of term %d:",i+1);
        scanf("%d",&p);
        if(head1->coeff==0){
        head1->coeff=c;
        head1->pow=p;
        }
        else{
        nw1=(struct node*)malloc(sizeof(struct node));
        nw1->coeff=c;
        nw1->pow=p;
        nw1->next=NULL;
        tail1->next=nw1;
        tail1=nw1;
        }
    }
}
void creationP2(){
    int n,i,c,p;
    printf("Enter number of terms of polynomial 2: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter coefficient of term %d:",i+1);
        scanf("%d",&c);
        printf("Enter power of term %d:",i+1);
        scanf("%d",&p);
        if(head2->coeff==0){
        head2->coeff=c;
        head2->pow=p;
        }
        else{
        nw2=(struct node*)malloc(sizeof(struct node));
        nw2->coeff=c;
        nw2->pow=p;
        nw2->next=NULL;
        tail2->next=nw2;
        tail2=nw2;
        }
    }
}
void addition(){
    temp1=head1;
    temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->pow==temp2->pow){
            if(head->coeff==0){ 
            head->coeff=temp1->coeff+temp2->coeff; 
            head->pow=temp1->pow; 
            } 
            else{
            nw=(struct node*)malloc(sizeof(struct node));
            nw->coeff=temp1->coeff+temp2->coeff;
            nw->pow=temp1->pow;
            nw->next=NULL;
            tail->next=nw;
            tail=nw;
            }
        temp1=temp1->next;
        temp2=temp2->next;
        }
    else if(temp1->pow>temp2->pow){
        if(head->coeff==0){ 
            head->coeff=temp1->coeff; 
            head->pow=temp1->pow; 
            } 
            else{
            nw=(struct node*)malloc(sizeof(struct node));
            nw->coeff=temp1->coeff;
            nw->pow=temp1->pow;
            nw->next=NULL;
            tail->next=nw;
            tail=nw;
        }
        temp1=temp1->next;
    }
    else if(temp1->pow<temp2->pow){
        if(head->coeff==0){ 
            head->coeff=temp2->coeff; 
            head->pow=temp2->pow; 
            } 
            else{
            nw=(struct node*)malloc(sizeof(struct node));
            nw->coeff=temp2->coeff;
            nw->pow=temp2->pow;
            nw->next=NULL;
            tail->next=nw;
            tail=nw;
        }
        temp2=temp2->next;
    }
}
while(temp1!=NULL){ 
    if(head->coeff==0){ 
    head->coeff=temp1->coeff; 
    head->pow=temp1->pow; 
    } 
    else{ 
    nw=((struct node*)malloc(sizeof(struct node))); 
    nw->coeff=temp1->coeff; 
    nw->pow=temp1->pow; 
    nw->next=NULL; 
    tail->next=nw; 
    tail=nw; 
    } 
    temp1=temp1->next; 
 } 
 while(temp2!=NULL){ 
    if(head->coeff==0){ 
    head->coeff=temp2->coeff; 
    head->pow=temp2->pow; 
    } 
    else{ 
    nw=((struct node*)malloc(sizeof(struct node))); 
    nw->coeff=temp2->coeff; 
    nw->pow=temp2->pow; 
    nw->next=NULL; 
    tail->next=nw; 
    tail=nw; 
    } 
    temp2=temp2->next; 
 } 
 }
void displayP1(){
    if(head1->coeff==0){
        printf("Empty");
    }
    else{
        temp1=head1;
        while(temp1!=NULL){
            printf("%dx^%d+",temp1->coeff,temp1->pow);
            temp1=temp1->next;
        }
    }
    printf("\n");
}
void displayP2(){
    if(head2->coeff==0){
        printf("Empty");
    }
    else{
        temp2=head2;
        while(temp2!=NULL){
            printf("%dx^%d+",temp2->coeff,temp2->pow);
            temp2=temp2->next;
        }
    }
    printf("\n");
}
void displayP3(){
    if(head->coeff==0){
        printf("Empty");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%dx^%d+",temp->coeff,temp->pow);
            temp=temp->next;
        }
    }
    printf("\n");
}
