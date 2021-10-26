#include<stdio.h>
#include<stdlib.h>
//二叉排序树建立求最大值，求深度
//前中后遍历（递归）
typedef int Element;   //节点数据类型重命名
typedef struct BiNode{
    Element data;
    struct BiNode *lchild;   //左子树
    struct BiNode *rchild;  //右子树
}Node;
typedef struct {
    Node *root;
}BiTree;
void insert (BiTree *tree,int value){
    Node* node=malloc(sizeof(Node));
    node->data=value;
    node->lchild=NULL;
    node->rchild=NULL;
    if(tree->root==NULL){
        tree->root=node;
    }else{
        Node *temp=tree->root;
        while(temp!=NULL){
            if(value<temp->data){
                if(temp->lchild==NULL){
                    temp->lchild=node;
                    return;
                } else{
                    temp=temp->lchild;
                }
            } else{
                if(temp->rchild==NULL){
                    temp->rchild=node;
                    return;
                }else{
                    temp=temp->rchild;
                }
            }
        }
    }
}
void preOrder(Node* node){
    if(node!=NULL){
        printf("%d\t",node->data);
        preOrder(node->lchild);
        preOrder(node->rchild);
    }
}
void midOrder(Node *node){
    if(node!=NULL){
        midOrder(node->lchild);
        printf("%d\t",node->data);
        midOrder(node->rchild);
    }
}
void lastOrder(Node *node){
    if(node!=NULL){
        lastOrder(node->lchild);
        lastOrder(node->rchild);
        printf("%d\t",node->data);
    }
}
int getHeight(Node *node){
    if(node==NULL){
        return 0;
    }else{
        int leftHeight= getHeight(node->lchild);
        int rightHeight= getHeight(node->rchild);
        int max=leftHeight;
        if(max<rightHeight){
            max=rightHeight;
        }
        return max+1;
    }
}
int getMaxNum(Node *node){
    if(node==NULL){
        return -1;
    }else{
        int leftValue= getMaxNum(node->lchild);
        int rightValue= getMaxNum(node->rchild);
        int value=node->data;
        int max=value;
        if(leftValue>max){
            max=leftValue;
        }
        if(rightValue>max){
            max=rightValue;
        }
        return max;
    }
}
int main(){
int arr[7]={6,3,8,2,5,1,7};
BiTree tree;
tree.root=NULL;
int i=0;
for(i=0;i<7;i++){
    insert(&tree,arr[i]);
}
    midOrder(tree.root);
    printf("\nHeight:");
    int height=getHeight(tree.root);
    printf("%d\n",height);
    printf("maxNum:");
    int max=getMaxNum(tree.root);
    printf("%d\n",max);
    return 0;
}
