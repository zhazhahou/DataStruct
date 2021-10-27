#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct LinkStackNode{
    DataType data;
    struct LinkStackNode *next;
}LinkStackNode,*LinkStack;
LinkStack InitStack(){
    LinkStack top;
    top=(LinkStack) malloc(sizeof(LinkStack));
    top->next=NULL;
    return top;
}
int EmptyStack(LinkStack top){
    int flag;
    if(top->next==NULL){
        printf("Stack is empty");
        flag=1;//1代表栈为空
    } else{
        flag=0; //0代表栈非空
        printf("empty is not empty");
    }
    return flag;
}
int  Push(LinkStack top,DataType x){
    int flag;
    LinkStackNode *node=(LinkStackNode *) malloc(sizeof(LinkStackNode));
    if(node==NULL){
        flag=1; //新节点创建失败
    }
    if(node!=NULL){
        node->data=x;
        node->next=top->next;
        top->next=node;
        flag=0;//新节点创建成功
    }
    return flag;

}
int  Pop(LinkStack top,DataType *x){
    int flag;
    LinkStackNode *node;
    if(top==NULL){
        flag=1;//栈为空出栈失败
    } else {
        node = top->next;
        *x = node->data;
        top->next = node->next;
        free(node);
        flag = 0;//出栈顶元素成功
    }
    return flag;
}
int  GetTop(LinkStack top,DataType *x){
    int flag;
    if(top->next==NULL){
        flag=1;//栈为空无法出栈顶元素
    } else{
        *x=top->data;
        flag=1;
    }
    return flag;
}
int main(){
    DataType x=5;//进栈元素
    DataType y; //出栈顶元素
    LinkStack top;
    top=InitStack();

    return 0;
}
