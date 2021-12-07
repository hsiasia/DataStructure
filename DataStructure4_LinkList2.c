#include <stdio.h>
#include <stdlib.h>

#define Maxsize 1000

struct Node{
    int info;
    struct Node *next;
};
typedef struct Node* NodePtr;

struct LinkList{
    NodePtr front, rear;
};
struct LinkList LL;

void Enqueue(int x){
    NodePtr p;
    p=malloc(sizeof(struct Node));

    p->info=x;
    p->next=NULL;
    if(LL.rear==NULL){
        LL.front=p;
    }
    else{
        LL.rear->next=p;
    }
    LL.rear=p;
}

int Dequeue(){
    NodePtr p;
    p=malloc(sizeof(struct Node));
    int x;

    if(LL.front==NULL){
        printf("> -3\n");
        return 0;
    }
    p=LL.front;
    x=p->info;

    LL.front=p->next;

    if(LL.front==NULL){
        LL.rear=NULL;
    }
    return x;
}

void GetFront(){
    int x;

    if(LL.front==NULL){
        printf("> -2\n");
        return 0;
    }

    x=LL.front->info;
    printf("> %d\n",x);
}

int main()
{
    int input;
    int InputNum;
    while(scanf("%d", &input)&&input!=-1){
        switch(input) {
        case 1:
            scanf("%d", &InputNum);
            Enqueue(InputNum);
            break;
        case 3:
            Dequeue();
            break;
        case 2:
            GetFront();
            break;
        default:
            break;
        }
    }
    return 0;
}
