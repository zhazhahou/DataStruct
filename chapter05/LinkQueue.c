#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct LinkNode{
    DataType data;
    struct LinkNode *next;
}LinkNode;
typedef struct LinkQueue{
    LinkNode *rear,*front;
}LinkQueue;
//带有头节点的链队列

//初始化队列
void InitQueue(LinkQueue queue){
    queue.rear=queue.front=(LinkQueue *) malloc(sizeof(LinkQueue));
    queue.front->next=NULL;
}
//判断队列是否为空
int EmptyQueue(LinkQueue queue){
    if(queue.rear==queue.front){
        return 1;//1表示为空
    } else{
        return 0; //0表示非空
    }
}
//元素进队列
void EnQueue(LinkQueue queue){
    DataType x=0;
    printf("请输入入队的元素:");
    scanf("%d",&x);
    while (x!=9999){
        LinkNode *s=(LinkNode *) malloc(sizeof(LinkNode));
        s->data=x;
        printf("请输入入队的元素:");
        s->next=queue.front->next;
        queue.rear->next=s;
        queue.rear=s;
        scanf("%d",&x);
    }
}

//元素出队列
void DeQueue(LinkQueue queue,DataType *x){
    LinkNode *s=(LinkNode *) malloc(sizeof (LinkNode));
    queue.front=queue.front->next;//使front指针指向队列中的第一个元素
    if(!EmptyQueue(queue)){
         s=queue.front;
         *x=queue.front->data;
         queue.front->next=s->next;
         if(queue.front==queue.rear){
             queue.front=queue.rear;
         }
        free(s);

    } else{
        printf("队列中的元素为空，没有元素可以出队列");
    }
}

void main(){
  LinkQueue queue;
    InitQueue(queue);
    EmptyQueue(queue);
}

