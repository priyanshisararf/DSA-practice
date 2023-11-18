#include<stdio.h>
struct stack{
    int top;
    int a[5];
}st;
char infix[10];
char postfix[10];
void post();
void push(int);
char pop();
void main(){
    st.top=-1;
    printf("Enter infix expression: ");
    scanf("%s",infix);
    post();
}
void post(){
    int i,j=0;
    for(i=0;infix[i]!='\0';i++){
        switch(infix[i]){
            case '+':
            while(st.a[st.top]>=1)
            postfix[j++]=pop();
            push(1);
            break;
            case '-':
            while(st.a[st.top]>=1)
            postfix[j++]=pop();
            push(2);
            break;
            case '*':
            while(st.a[st.top]>=3)
            postfix[j++]=pop();
            push(3);
            break;
            case '/':
            while(st.a[st.top]>=3)
            postfix[j++]=pop();
            push(4);
            break;
            case '^':
            while(st.a[st.top]>=3)
            postfix[j++]=pop();
            push(5);
            break;
            case'(':
            push(0);
            break;
            case')':
            while(st.a[st.top]!=0)
            postfix[j++]=pop();
            st.top--;
            break;
            default:
            postfix[j++]=infix[i];
            break;
        }
    }
    while(st.top>=0)
    postfix[j++]=pop();
    printf("Postfix expression: %s",postfix);
}
void push(int x){
    st.top++;
    st.a[st.top]=x;
}
char pop(){
    int el;
    char e;
    el=st.a[st.top];
    st.top--;
    switch(el){
        case 1:
        e='+';
        break;
        case 2:
        e='-';
        break;
        case 3:
        e='*';
        break;
        case 4:
        e='/';
        break;
        case 5:
        e='^';
        break;
    }
    return (e);
}
