#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int *data, int left, int right){
    int pivot,i,j;

    if(left>=right){
        return;
    }

    pivot=data[left];
    i=left+1;
    j=right;

    while(1){
        while(i<=right){
            if(data[i]>pivot){
                break;
            }
            i=i+1;
        }
        while(j>left){
            if(data[j]<pivot){
                break;
            }
            j=j-1;
        }
        if(i>j){
            break;
        }
        swap(&data[i], &data[j]);
    }

    swap(&data[left], &data[j]);
    QuickSort(data, left, j-1);
    QuickSort(data, j+1, right);
}


int main(){
    int n;

    while(scanf("%d", &n)&&n!=-1){
        int data[n];

        for(int i=0; i<n; i++){
            scanf("%d", &data[i]);
        }

        QuickSort(data, 0, n - 1);

        printf("> ");
        for(int i=0; i<n; i++){
            printf("%d ", data[i]);
        }
        printf("\n");

        n=0;
        printf("\n");
    }
}

