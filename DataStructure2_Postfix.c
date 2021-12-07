#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 100

void inToPostfix(char*, char*); //中序轉後序
int priority(char); //運算子權重
int calPostfix(char*);  //後序運算
int cal(char, int, int);    //運算

int main() {
    char infix[Maxsize]={'\0'};
    char postfix[Maxsize]={'\0'};

    while(scanf("%s", infix)&&((infix[0]!='-')&&(infix[1]!='1'))){
        toPostfix(infix,postfix);
        printf(">");
        for(int i = 0; i<strlen(postfix); i++) {
            printf(" %c",postfix[i]);
        }
        printf("\n> %d\n\n",calPostfix(postfix));
        memset(infix, '\0', sizeof infix);
        memset(postfix, '\0', sizeof postfix);
    }
    return 0;
}

void toPostfix(char* infix, char* postfix) {
    char stack[Maxsize] = {'\0'};

    int i, j, top;
    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++){
        switch(infix[i]) {
        case '(':
            stack[++top] = infix[i];
            break;
        case '+': case '-': case '*': case '/': case '^':
            while(priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
            break;
        case ')':
            while(stack[top] != '('){
                postfix[j++] = stack[top--];
            }
            top--;  //跳過左括號
            break;
        default:
            postfix[j++] = infix[i];
        }
    }
    while(top > 0) {
        postfix[j++] = stack[top--];
    }
}

int priority(char op) {
    switch(op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int calPostfix(char* postfix) {
    char opd[1] = {'\0'};
    int stack[Maxsize] = {0};

    int top = 0;
    for(int i = 0; postfix[i] != '\0'; i++){
        switch(postfix[i]) {
            case '+': case '-': case '*': case '/': case '^':
                stack[top-1] = cal(postfix[i],stack[top-1],stack[top]);
                top--;
                break;
            default:
                opd[0] = postfix[i];
                stack[++top] = atoi(opd);
        }
    }
    return stack[top];
}

int cal(char op, int p1, int p2) {
    switch(op) {
        case '+': return p1+p2;
        case '-': return p1-p2;
        case '*': return p1*p2;
        case '/': return p1/p2;
        case '^': return pow(p1,p2);
    }
}
