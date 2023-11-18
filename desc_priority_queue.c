#include<stdio.h>
void enqueue();
void dequeue();
void priority();
void display();
struct priority_queue{
    int a[5];
    int front,rear;
}pq;
void main(){
     int ch;
    pq.front=-1;
    pq.rear=-1;
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
    if(pq.rear==4)
    printf("Queue is full\n");
    else{
        printf("Enter item: ");
        scanf("%d",&item);
        if(pq.rear==-1){
            pq.rear++;
            pq.front++;
            pq.a[pq.rear]=item;
        }
        else{
        pq.rear++;
        pq.a[pq.rear]=item;
        priority();
    }
}}
void dequeue(){
    if(pq.rear==-1)
    printf("Queue is empty\n");
    else{
        if(pq.rear==pq.front){
            pq.rear=-1;
            pq.front=-1;
        }
        else
        pq.front++;
    }
}
void display(){
    int temp;
    temp=pq.front;
    if(pq.rear==-1)
    printf("Queue is empty\n");
    else{
    while(temp<=pq.rear){
        printf("%d\t",pq.a[temp]);
        temp++;
    }
}}
void priority(){
    int i,j,temp;
    for(i=1;i<=pq.rear;i++){
        for(j=0;j<i;j++){
            if(pq.a[j]<pq.a[i]){
                temp=pq.a[j];
                pq.a[j]=pq.a[i];
                pq.a[i]=temp;
            }
        }
    }
}