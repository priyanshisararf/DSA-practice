#include<stdio.h>
void enqueue();
void dequeue();
void display();
struct circular_queue{
    int front,rear;
    int a[5];
}cq;
void main(){
    int ch;
    cq.front=-1;
    cq.rear=-1;
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
    if(cq.front==((cq.rear+1)%5))
    printf("Queue is full");
    else{
        int item;
        printf("Enter item: ");
        scanf("%d",&item);
        if(cq.rear==-1){
            cq.rear++;
            cq.front++;
            cq.a[cq.rear]=item;
        }
        else{
            cq.rear=(cq.rear+1)%5;
            cq.a[cq.rear]=item;
        }
    }
}
void dequeue(){
    if(cq.rear==-1)
    printf("Queue is empty");
    else{
        if(cq.rear==cq.front){
            cq.front=-1;
            cq.rear=-1;
        }
        else
        cq.front=(cq.front+1)%5;
    }
}
void display(){
    int temp;
    if(cq.rear==-1)
    printf("Queue is empty");
    else{
        temp=cq.front;
        while(temp!=cq.rear){
            printf("%d\t",cq.a[temp]);
            temp=(temp+1)%5;
        }
        printf("%d",cq.a[temp]);
    }
}
