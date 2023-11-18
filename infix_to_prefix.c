#include<stdio.h>
struct stack{
    int top;
    int a[5];
}st;
char infix[10];
char prefix[10];
void pre();
void push(int);
char pop();
void main(){
    st.top=-1;
    printf("Enter infix expression: ");
    scanf("%s",infix);
    int i,temp;
    int l=strlen(infix);
    for(i=0;i<(l/2);i++){
        temp=infix[i];
        infix[i]=infix[l-i-1];
        infix[l-i-1]=temp;
    }
    pre();
}
void pre(){
    int i,j=0,temp,l;
    for(i=0;infix[i]!='\0';i++){
        switch(infix[i]){
            case '+':
            while(st.a[st.top]>1)
            prefix[j++]=pop();
            push(1);
            break;
            case '-':
            while(st.a[st.top]>1)
            prefix[j++]=pop();
            push(2);
            break;
            case '*':
            while(st.a[st.top]>3)
            prefix[j++]=pop();
            push(3);
            break;
            case '/':
            while(st.a[st.top]>3)
            prefix[j++]=pop();
            push(4);
            break;
            case '^':
            while(st.a[st.top]>3)
            prefix[j++]=pop();
            push(5);
            break;
            case ')':
            push(0);
            break;
            case '(':
            while(st.a[st.top]!=0)
            prefix[j++]=pop();
            break;
            default:
            prefix[j++]=infix[i];
            break;
        }
    }
    while(st.top>=0)
    prefix[j++]=pop();
    l=strlen(prefix);
    for(i=0;i<(l/2);i++){
        temp=prefix[i];
        prefix[i]=prefix[l-i-1];
        prefix[l-i-1]=temp;
    }
    printf("Prefix expression: %s",prefix);
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