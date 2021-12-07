#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMIUM 1024

//int sumsize=0;

struct Node {
    int index;
    int i;
    int j;
    int next[MAXMIUM];
};

typedef struct Node* Nodeptr;
Nodeptr arr[MAXMIUM];

/*
typedef struct Node NodeArr;
NodeArr Stack[MAXMIUM];
*/
int matrix[MAXMIUM][MAXMIUM];
int array[MAXMIUM];
int flag[MAXMIUM];
int reg=0;
/*
int pipe[MAXMIUM][MAXMIUM];

int reg=0;
int reg2=0;
int index=1;

void push(int x,int y){

    NodeArr N;
    N.i=x;
    N.j=y;
    printf("x=%d y=%d\n",N.i,N.j);
    Stack[reg++]=N;
    printf("x=%d y=%d\n",Stack[reg-1].i,Stack[reg-1].j);
}
NodeArr pop(){
    return Stack[reg2++];
}

void find(int i,int j){
    if(matrix[i][j-1]==1){
        if(pipe[i][j-1]==0){
            push(i,j-1);
            pipe[i][j-1]=index+1;
        }
        //arr[index][reg].i=i;
        //arr[index][reg++].j=j-1;
        printf("index=%d x=%d y=%d\n",index,i,j-1);
    }
    if(matrix[i][j+1]==1){
        if(pipe[i][j+1]==0){
            push(i,j+1);
            pipe[i][j+1]=index+1;
        }
        //arr[index][reg].i=i;
        //arr[index][reg++].j=j+1;
        printf("index=%d x=%d y=%d\n",index,i,j+1);
    }
    if(matrix[i-1][j]==1){
        if(pipe[i-1][j]==0){
            push(i-1,j);
            pipe[i-1][j]=index+1;
        }
        //arr[index][reg].i=i-1;
        //arr[index][reg++].j=j;
        printf("index=%d x=%d y=%d\n",index,i-1,j);
    }
    if(matrix[i+1][j]==1){
        if(pipe[i+1][j]==0){
            push(i+1,j);
            pipe[i+1][j]=index+1;
        }
        //arr[index][reg].i=i+1;
        //arr[index][reg++].j=j;
        printf("index=%d x=%d y=%d\n",index,i+1,j);
    }
    index++;
    if(Stack[reg2].i!='\0'){
        NodeArr N=pop();
        find(N.i,N.j);
    }
}
*/
void push(int num){
    int i=0;
    while(array[i]!=-1){
        i++;
    }
    array[i]=num;
}

int pop(){
    int value=array[0];

    int i=0;
    while(array[i]!=-1){
        array[i]=array[i+1];
        i++;
    }
    return value;
}


BFS(int time){
    int temp_arr[MAXMIUM];
    memset(temp_arr,-1,sizeof(temp_arr));

    //printf("time%d: ",time);
    for(int i=0;array[i]!=-1;i++){
        //printf("%d ",array[i]);
        matrix[arr[array[i]]->i][arr[array[i]]->j]=time;
    }
    //printf("\n");
    int n=0;
    while(array[0]!=-1){
        temp_arr[n++]=pop();
    }

    for(int i=0;temp_arr[i]!=-1;i++){
        for(int y=0;arr[temp_arr[i]]->next[y]!=-1;y++){
            int component=arr[temp_arr[i]]->next[y];
            if(flag[component]!=1){
                push(component);
                flag[component]=1;
                //free(arr[component]);
            }
        }
    }
    if(array[0]!=-1){
        time++;
        BFS(time);
    }
}

int main()
{
    int n,m;

    //int matrix[n][m];
    memset(matrix,-1,sizeof matrix);
    memset(array,-1,sizeof array);
    memset(flag,-1,sizeof flag);
    //memset(pipe,0,sizeof pipe);

    scanf("%d",&n);
    scanf("%d",&m);

    while(n!=-1&&m!=-1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&matrix[i][j]);
            }
        }

        /*for(int i=0;i<n;i++){
            printf("> ");
            for(int j=0;j<m;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }*/

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    Nodeptr N = (Nodeptr)malloc(sizeof(struct Node));
                    N->index=reg;
                    N->i=i;
                    N->j=j;
                    memset(N->next,-1,sizeof(N->next));
                    arr[reg++]=N;
                    //free(N);
                    //printf("%d %d %d\n",arr[reg-1]->index,arr[reg-1]->i,arr[reg-1]->j);
                }
            }
        }
        for(int x=0;x<reg;x++){
            int i=arr[x]->i;
            int j=arr[x]->j;
            int reg2=0;

            if(matrix[i-1][j]==1){
                //printf("1\n");
                for(int y=0;y<reg;y++){
                    if(arr[y]->i==i-1&&arr[y]->j==j){
                        arr[x]->next[reg2++]=y;
                    }
                }
            }
            if(matrix[i+1][j]==1){
                //printf("2\n");
                for(int y=0;y<reg;y++){
                    if(arr[y]->i==(i+1)&&arr[y]->j==j){
                        arr[x]->next[reg2++]=y;
                    }
                }
            }
            if(matrix[i][j-1]==1){
                //printf("3\n");
                for(int y=0;y<reg;y++){
                    if(arr[y]->i==i&&arr[y]->j==j-1){
                        arr[x]->next[reg2++]=y;
                    }
                }
            }
            if(matrix[i][j+1]==1){
                //printf("4\n");
                for(int y=0;y<reg;y++){
                    if(arr[y]->i==i&&arr[y]->j==j+1){
                        arr[x]->next[reg2++]=y;
                    }
                }
            }
        }
        /*for(int x=0;x<reg;x++){
            printf("index%d: ",x);
            for(int y=0;arr[x]->next[y]!=-1;y++){
                printf("%d ",arr[x]->next[y]);
            }
            printf("\n");
        }*/

        push(0);
        flag[0]=1;
        BFS(1);

        for(int i=0;i<n;i++){
            printf("> ");
            for(int j=0;j<m;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        memset(matrix,-1,sizeof matrix);
        memset(array,-1,sizeof array);
        memset(flag,-1,sizeof flag);
        scanf("%d",&n);
        scanf("%d",&m);
        reg=0;
    }



    return 0;
}
