#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 100

struct stack {
    int top;
    char data[Maxsize];
};
struct stack s;

int Full(){
    if(s.top==Maxsize-1){
        return 1;
    }
    else
        return 0;
}
int Empty(){
    if(s.top==-1){
        return 1;
    }
    else
        return 0;
}
void push(char input){
    if(Full(s)==0){
        s.top++;
        s.data[s.top]=input;
    }
    else{
        return 0;
    }
}
char pop(){
    if(Empty(s)==0){
        char output=s.data[s.top];
        s.top--;
        return output;
    }
    else{
        return 0;
    }
}
int main()
{
    char infix[Maxsize]={'\0'};

    while(scanf("%s",infix)&&((infix[0]!='-')&&(infix[1]!='1'))){
    s.top=-1;
    int ans = 1;
    for(int i = 0; infix[i] != '\0'; i++){
        switch(infix[i]) {
        case '(': case '[': case '{':
            push(infix[i]);
            break;
        case ')':
            if(s.data[s.top] != '('){
                ans=0;
            }
            s.top--;  //跳過左括號
            break;
        case ']':
            if(s.data[s.top] != '['){
                ans=0;
            }
            s.top--;  //跳過左括號
            break;
        case '}':
            if(s.data[s.top] != '{'){
                ans=0;
            }
            s.top--;  //跳過左括號
            break;
        default:
            break;
        }
    }
    if(ans==1){
        printf("> Balanced\n");
        printf("\n");
    }
    else{
        printf("> Unbalanced\n");
        printf("\n");
    }
    memset(infix, '\0', sizeof infix);
    }
}
