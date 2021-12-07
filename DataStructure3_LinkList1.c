#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    int next;
};
struct Node node[Maxsize+1];

struct LinkList{
    int front, rear;
};
struct LinkList LL;

void Enqueue(int x){
    int p=(rand()%1000)+1;
    while(node[p].info!=NULL){
        p=(rand()%1000)+1;
    }
    node[p].info=x;
    node[p].next=NULL;
    if(LL.rear==NULL){
        LL.front=p;
    }
    else{
        node[LL.rear].next=p;
    }
    LL.rear=p;
}

int Dequeue(){
    int p;
    int x;

    if(LL.front==NULL){
        printf("> -3\n");
        return 0;
    }
    p=LL.front;
    x=node[p].info;

    LL.front=node[p].next;

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

    x=node[LL.front].info;
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
