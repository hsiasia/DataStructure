#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMIUM 100

int sumsize=0;

struct Node {
    int freq;
    struct Node *left, *right;
};

struct Heap {
    int size;
    int capacity;
    struct Node** array;
};

struct Node* NewNode(int freq){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

    temp->left=temp->right=NULL;
    temp->freq=freq;

    return temp;
}

struct Heap* NewHeap(int capacity){
    struct Heap* Heap=(struct Heap*)malloc(sizeof(struct Heap));

    Heap->size=0;

    Heap->capacity=capacity;

    Heap->array=(struct Node**)malloc(Heap->capacity*sizeof(struct Node*));
    return Heap;
}

struct Node* extractMin(struct Heap* Heap){
    struct Node* temp=Heap->array[0];
    Heap->array[0]=Heap->array[Heap->size-1];

    --Heap->size;
    Heapify(Heap, 0);

    return temp;
}

void Heapify(struct Heap* Heap, int index){
    int smallest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<Heap->size && Heap->array[left]->freq<Heap->array[smallest]->freq)
        smallest = left;
    if(right<Heap->size && Heap->array[right]->freq<Heap->array[smallest]->freq)
        smallest = right;
    if(smallest!=index){
        swapHeap(&Heap->array[smallest],&Heap->array[index]);
        Heapify(Heap, smallest);
    }
}

void swapHeap(struct Node** a, struct Node** b){
    struct Node* t=*a;
    *a=*b;
    *b=t;
}

struct Heap* BuildHeap(int freq[], int size){
    struct Heap* Heap=NewHeap(size);

    for(int i=0; i<size; ++i)
        Heap->array[i]=NewNode(freq[i]);

    Heap->size=size;

    int n=Heap->size-1;
    int i;

    for(i=(n-1)/2; i>=0; --i)
        Heapify(Heap, i);

    return Heap;
}

struct Node* BuildTree(int freq[], int size){
    struct Node *left, *right, *top;

    struct Heap* Heap = BuildHeap(freq, size);

    while(Heap->size!=1){
        left=extractMin(Heap);
        right=extractMin(Heap);

        top=NewNode(left->freq+right->freq);
        top->left=left;
        top->right=right;

        insertMinHeap(Heap, top);
    }
    return extractMin(Heap);
}

void insertMinHeap(struct Heap* Heap, struct Node* minHeapNode){
    ++Heap->size;
    int i=Heap->size-1;

    while(i&&minHeapNode->freq < Heap->array[(i-1)/2]->freq){
        Heap->array[i]=Heap->array[(i-1)/2];
        i=(i-1)/2;
    }
    Heap->array[i]=minHeapNode;
}

void Huffman(int freq[], int size){
    struct Node* root=BuildTree(freq, size);
    treeorder(root, 0);
    //free(root);
}

void treeorder(struct Node* root, int top){
    if(root->left){
        treeorder(root->left, top + 1);
    }
    if(root->right){
        treeorder(root->right, top + 1);
    }
    if(!(root->left)&&!(root->right)){
        //printf("%d \n",root->freq*top);
        sumsize+=root->freq*top;
    }
    //free(root);
}

int main()
{
    int time[57];
    char arr[1000]={'\0'};

    while(gets(arr)&&arr[0]!='-1'&&arr[1]!='1'){
        memset(time,0,sizeof time);

        for(int i=0;arr[i]!='\0';i++){//­pºâ¦¸¼Æ
            if(isalpha(arr[i])){
                time[(int)arr[i]-65]++;
            }
        }

        int size=0;
        for(int i=0;i<57;i++){
            if(time[i]!=0){
                size++;
            }
        }

        int freq[size];

        int j=-1;
        for(int i=0;i<size;i++){
            do{
                j++;
            }while(time[j]==0);
            freq[i]=time[j];
            //printf("%d\n",freq[i]);
        }

        Huffman(freq, size);
        printf("> %d\n",sumsize);

        memset(arr,'\0',sizeof arr);
        sumsize=0;
    }
    return 0;
}
