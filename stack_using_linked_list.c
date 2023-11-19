#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node *nw,*top,*temp;
void main(){
    nw=(struct node*)malloc(sizeof(struct node));
    nw->data=0;
    nw->next=NULL;
    top=nw;
    int choice;
    do{
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
        }
    }while(choice<4);
}
void push(){
    int item;
    printf("Enter item: ");
    scanf("%d",&item);
    if(top->data==0)
    top->data=item;
    else{
    nw=(struct node*)malloc(sizeof(struct node));
    nw->data=item;
    nw->next=top;
    top=nw;
    }
}
void pop(){
    if(top->data==0)
    printf("Stack is empty");
    else{
        temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
}
void display(){
    if(top->data==0)
    printf("Stack is empty");
    else{
    temp=top;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    }
}