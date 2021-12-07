#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int key;
    struct node *left;
    struct node *right;
};
//node_t *root;
//typedef struct node* node_pt;

struct node* insert(struct node* input_root, struct node* new_node);
void preorder(struct node* input_root);
void postorder(struct node* input_root);

int main()
{
    int reg,input;
    //struct node* root = (struct node*)malloc(sizeof(struct node));

    while(scanf("%d", &reg)&&reg!=-1){
        struct node* root = (struct node*)malloc(sizeof(struct node));

        for(int i=0;i<reg;i++){
            scanf("%d", &input);
            if(i==0){
                //printf("step 1\n");
                root->data=input;
                root->left=NULL;
                root->right=NULL;
                root->key=i;
            }
            else{
                //printf("step 2\n");
                struct node* input_node = (struct node*)malloc(sizeof(struct node));
                input_node->data=input;
                input_node->key=i;

                root = insert(root,input_node);
                //printf("%d\n",root->data);
                //free(input_node);
            }
        }
        printf("> Preorder: ");
        preorder(root);
        printf("\n> Postorder: ");
        postorder(root);
        printf("\n");
        //free(root);
    }
    return 0;
}

struct node* insert(struct node* input_root, struct node* new_node){
    int flag=0;
    struct node* pt = (struct node*)malloc(sizeof(struct node));
    pt=input_root;

    while(flag!=1){
        if(new_node->data > pt->data){
            if(pt->right!=NULL){
                //printf("1-1 %dvs%d\n key:%d,%d\n",pt->data,new_node->data,pt->key,new_node->key);
                pt=pt->right;
                }
            else{
                //printf("1-2 %dvs%d\n key:%d,%d\n",pt->data,new_node->data,pt->key,new_node->key);
                pt->right=new_node;
                flag=1;
                //printf("insert right: %d\n",new_node->data);
                new_node->left=NULL;
                new_node->right=NULL;
            }
        }
        else if(new_node->data <= pt->data){
            //printf("2-2 %dvs%d\n key:%d,%d\n",pt->data,new_node->data,pt->key,new_node->key);
            if(pt->left!=NULL){
                //printf("2-1 %dvs%d\n key:%d,%d\n",pt->data,new_node->data,pt->key,new_node->key);
                pt=pt->left;
                }
            else{
                //printf("2-2 %dvs%d\n key:%d,%d\n",pt->data,new_node->data,pt->key,new_node->key);
                pt->left=new_node;
                flag=1;
                //printf("insert left: %d\n",new_node->data);
                new_node->left=NULL;
                new_node->right=NULL;
            }
        }
    }
    //free(pt);
    return input_root;
}

void postorder(struct node* input_root){
    if(input_root->left!=NULL){
        postorder(input_root->left);
    }

    if(input_root->right!=NULL){
        postorder(input_root->right);
    }
    printf("%d ",input_root->data);
    //free(input_root);
}

void preorder(struct node* input_root){
    printf("%d ",input_root->data);

    if(input_root->left!=NULL){
        preorder(input_root->left);
    }
    if(input_root->right!=NULL){
        preorder(input_root->right);
    }
}
