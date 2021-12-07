#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMIUM 1024
/*
struct Node {
    int index;
    int color;
};
*/
int Stack[MAXMIUM];
int color[MAXMIUM];

int V,S;
int reg=0;
int reg2=0;
int flag=1;

void push(int in_index, int in_color){

    Stack[reg++]=in_index;
    color[in_index]=in_color;

}

int pop(){

    return Stack[reg2++];

}

void BFS(int root,int rootcolor,int matrix[V][V]){
    //printf("12345\n");
    for(int i=0;i<V;i++){
        if(matrix[root][i]!=0){
            //printf("00000 %d\n",i);
            if(rootcolor==0){
                //printf("11111 %d\n",i);
                if(color[i]==0){
                    //printf("22222 %d\n",i);
                    //printf("OOPs %d\n",color[i]);
                    //printf("error %d\n",i);
                    flag=0;
                    return;
                }
                push(i,1);
            }
            else{
                //printf("33333 %d\n",i);
                if(color[i]==1){
                    //printf("44444 %d\n",i);
                    //printf("error %d\n",i);
                    flag=0;
                    return;
                }
                push(i,0);
            }
        }
    }
    for(int i=0;Stack[i]!='\0';i++)
        //printf("%d ",Stack[i]);
        //printf("\n");

    if(Stack[reg2]!='\0'){
        int next=pop();
        //printf("next %d %d\n",next,color[next]);
        BFS(next,color[next],matrix);
    }
}

int main()
{

    memset(Stack,'\0',sizeof Stack);
    memset(color,-1,sizeof color);

    scanf("%d",&V);
    scanf("%d",&S);

    while(V!=-1&&S!=-1){
        int matrix[V][V];

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                matrix[i][j]=0;
            }
        }

        for(int i=0;i<S;i++){
            int x,y;

            scanf("%d",&x);
            scanf("%d",&y);

            matrix[x][y]=1;
            matrix[y][x]=1;
        }

        color[0]=0;
        BFS(0,0,matrix);

        if(flag==0)
            printf("> Not bicolorable\n");
        else
            printf("> Bicolorable\n");

        for(int i=0;i<V;i++){
            printf("> ");
            for(int j=0;j<V;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        scanf("%d",&V);
        scanf("%d",&S);
        memset(Stack,'\0',sizeof Stack);
        memset(color,-1,sizeof color);
        reg=0;
        reg2=0;
        flag=1;

    }
    return 0;

}
