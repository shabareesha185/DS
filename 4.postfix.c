#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[20];
char postfix[20];

int top = -1;
int isEmpty(){
    return top == -1;
};

int isFull(){
    return top >= 20;
};

void push(char x){
    if(!isFull()){
        stack[++top] = x;
    };
};

char pop(){
    if(!isEmpty()){
        return stack[top--];
    };
    return '\0';
};

int priority(char x){
    if(x=='(') return 0;
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='%' || x=='/') return 2;
    return -1;
};

void infixToPostfix(char *exp){
    int i,j=0;
    int b=0;
    int len = strlen(exp);
    for (i = 0; i < len; i++){
        char c = exp[i];
        if(isalnum(c)){
            postfix[j++] = c;
        }else if(c=='('){
            push(c);
            b++;
        }else if(c==')'){
            b--;
            while(!isEmpty() && stack[top]!='('){
                postfix[j++] = pop();
            }
            if(isEmpty()){
                printf("Unbalanced parenthesis\n");
                return;
            }
            pop();
        }else if(c=='+' || c=='-' || c=='/' || c=='*' || c=='%'){
            while(!isEmpty() && priority(stack[top]) >= priority(c)){
                postfix[j++] = pop();
            }
            push(c);
        }else {
            printf("Invalid symbol\n");
            return;
        }
    }
    while (!isEmpty())     
        {
            if(stack[top] == '(' || stack[top] == ')'){
                printf("Unbalanced parenthesis");
                return;
            }
            postfix[j++] = pop();
        }
        postfix[j] = '\0';
        if(b==0){
            printf("%s\n",postfix);
        }else{
            printf("Unbalanced parenthesis");
            return;
        }
}

void main(){
    char exp[20];
    printf("Enter the Expression: ");
    scanf("%s",exp);
    infixToPostfix(exp);
}
