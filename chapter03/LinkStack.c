#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct LinkStackNode{
    DataType data;
    struct LinkStackNode *next;
}LinkStackNode,*LinkStack;
LinkStack InitStack(){
    LinkStack top;
    top=NULL;
    return top;
}
int EmptyStack(LinkStack top){
    if(top==NULL){
       // printf("Stack is empty");
        return 1;
    } else{
        //printf("Stack is not empty");
        return 0;
    }

}
LinkStack Push(LinkStack top){
    DataType x;
    printf("input push element:");
    scanf("%d",&x);
    while (x!=9999){
        LinkStackNode *node=(LinkStackNode *) malloc(sizeof(LinkStackNode));
        node->data=x;
        node->next=top;
        top=node;
        printf("input push element:");
        scanf("%d",&x);
    }
       return top;
}
LinkStack Pop(LinkStack top,DataType *x){
    LinkStackNode *node;
    if(EmptyStack(top)){
        return NULL;
    } else {
        *x= top->data;
        node= top;
        top= top->next;
        free(node);
        return top;
      }
}
int GetTop(LinkStack top,DataType *x){
    if(EmptyStack(top)){
        return 0;
    } else{
        *x=top->data;
        return 1;
    }
}
void ShowStack(LinkStack top){
    if(top==NULL){
        printf("stack is empty");
        return;
    }
    while (top!=NULL){
        printf("%d\t",top->data);
        top=top->next;
    }
}
int main(){
    DataType y=0; //出栈顶元素
    int flag;
    LinkStack top;
    top=InitStack();
    flag=EmptyStack(top);
    if(flag==1){
        printf("stack is empty");
    } else{
        printf("stack is not empty");
    }
      top=Push(top);
    printf("=============");
    flag=EmptyStack(top);
    if(flag==1){
        printf("stack is empty");
    } else{
        printf("stack is not empty");
    }
    //ShowStack(top);
//    while (top!=NULL){
//        top=Pop(top,&y);
//        printf("%d",y);
//    }
    printf("\n===============\n");
      //Pop(top,&y);
      //GetTop(top,&y);
     //printf("%d",y);
    return 0;
}

