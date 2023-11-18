#include<stdio.h>
struct stack{
    int top;
    int a[5];
}st;
void push(){
    int item;
    if (st.top==4)
    printf("Stack overflow");
    else{
        printf("Enter item: ");
        scanf("%d",&item);
        st.top++;
        st.a[st.top]=item;
    }
}
void pop(){
    if (st.top==-1)
    printf("Stack Underflow");
    else
    st.top--;
}
void display(){
    if (st.top==-1)
    printf("Stack Underflow");
    else{
        int temp=st.top;
        while(temp>=0){
            printf("%d\n",st.a[temp]);
            temp--;
        }
    }
}
void main(){
    int ch;
    st.top=-1;
    do{
    printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch){
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
    }while(ch<4);
}