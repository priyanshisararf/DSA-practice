#include<stdio.h>
void evaluate();
void push(int);
int pop();
char postfix[20];
struct stack{
    int top;
    int a[20];
}st;
void main(){
    st.top=-1;
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    evaluate();
    printf("RESULT: %d",st.a[st.top]);
}
void evaluate(){
    int i;
    int op1,op2;
    int res;
    for(i=0;postfix[i]!='\0';i++){
        switch(postfix[i]){
            case '+':
            op1=pop();
            op2=pop();
            res=(op2)+(op1);
            push(res);
            break;
            case '-':
            op1=pop();
            op2=pop();
            res=(op2)-(op1);
            push(res);
            break;
            case '*':
            op1=pop();
            op2=pop();
            res=(op2)*(op1);
            push(res);
            break;
            case '/':
            op1=pop();
            op2=pop();
            res=(op2)/(op1);
            push(res);
            break;
            case '^':
            op1=pop();
            op2=pop();
            res=(op2)^(op1);
            push(res);
            break;
            default:
            push(postfix[i]-48);
        }
    }

}
void push(int x){
    st.top++;
    st.a[st.top]=x;
}
int pop(){
    char el;
    el=st.a[st.top];
    st.top--;
    return el;
}