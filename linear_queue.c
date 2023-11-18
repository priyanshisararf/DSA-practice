#include<stdio.h>
void enqueue();
void dequeue();
void display();
struct linear_queue{
    int front,rear;
    int a[5];
}lq;
void main(){
    int ch;
    lq.front=-1;
    lq.rear=-1;
    do{
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n\nENTER CHOICE: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
        }
    }while(ch<4);
}
void enqueue(){
    int item;
    if(lq.rear==4)
    printf("Queue is full\n");
    else{
        printf("Enter item: ");
        scanf("%d",&item);
        if(lq.rear==-1){
            lq.rear++;
            lq.front++;
            lq.a[lq.rear]=item;
        }
        else{
        lq.rear++;
        lq.a[lq.rear]=item;
    }
}}
void dequeue(){
    if(lq.rear==-1)
    printf("Queue is empty\n");
    else{
        if(lq.rear==lq.front){
            lq.rear=-1;
            lq.front=-1;
        }
        else
        lq.front++;
    }
}
void display(){
    int temp;
    temp=lq.front;
    if(lq.rear==-1)
    printf("Queue is empty\n");
    else{
    while(temp<=lq.rear){
        printf("%d\t",lq.a[temp]);
        temp++;
    }
}}