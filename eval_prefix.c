#include<stdio.h>
#include<string.h>
void evaluate();
void push(int);
int pop();
char prefix[20];
struct stack{
    int top;
    int a[20];
}st;
void main(){
    st.top=-1;
    int i,temp;
    printf("Enter prefix expression: ");
    scanf("%s",prefix);
    int l=strlen(prefix);
    for(i=0;i<(l/2);i++){
        temp=prefix[i];
        prefix[i]=prefix[l-i-1];
        prefix[l-i-1]=temp;
    }
    evaluate();
    printf("RESULT: %d",st.a[st.top]);
}
void evaluate(){
    int i;
    int op1,op2;
    int res;
    for(i=0;prefix[i]!='\0';i++){
        switch(prefix[i]){
            case '+':
            op1=pop();
            op2=pop();
            res=(op1)+(op2);
            push(res);
            break;
            case '-':
            op1=pop();
            op2=pop();
            res=(op1)-(op2);
            push(res);
            break;
            case '*':
            op1=pop();
            op2=pop();
            res=(op1)*(op2);
            push(res);
            break;
            case '/':
            op1=pop();
            op2=pop();
            res=(op1)/(op2);
            push(res);
            break;
            case '^':
            op1=pop();
            op2=pop();
            res=(op1)^(op2);
            push(res);
            break;
            default:
            push(prefix[i]-48);
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