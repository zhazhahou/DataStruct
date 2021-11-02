#include<stdio.h>
#define MaxSize 100 //定义队列最大的容量
typedef int DataType;//定义DataType为int类型
typedef struct SeqQueue{
    DataType data[MaxSize];
    int rear;//队尾指针
    int front;//对头指针
}SeqQueue;

//初始化队列
void InitSeqQueue(SeqQueue *s){
    s->front=s->rear=0;
}
//判断队列是否为空
int EmptySeq(SeqQueue *s){
    if(s->rear==s->front){
        return 1; //空返回1
    } else{
        return 0;
    }
}
//判断队列是否已满
int FullQueue(SeqQueue *s){
    if((s->rear+1)%MaxSize==s->front){
        return 1; //满返回1
    } else{
        return 0;
    }
}
//元素入队列
void EnQueue(SeqQueue *s){
    DataType x = 0;
    //入队前判断是否已满
    if(!FullQueue(s)){
        printf("请输入你要入队的元素:");
        scanf("%d",&x);
        while (x!=9999){
            s->data[s->rear]=x;
            s->rear=(s->rear+1)%MaxSize;
            printf("请输入你要入队的元素:");
            scanf("%d",&x);
        }
    } else{
        printf("队列已满！！！");
    }
}

//元素出队列   x保存出队的元素
void DeQueue(SeqQueue *s,DataType *x){
    //出队前判断是否已空
     if(!EmptySeq(s)){
         *x=s->data[s->front];
         s->front=(s->front+1)%MaxSize;
     } else{
         printf("队列已空");
     }
}
//输出队列中的队头元素
void GetQueueFront(SeqQueue *s){
    DataType x=0;
   if(!EmptySeq(s)){
       x=s->data[s->front];
       printf("队头元素为%d\n",x);
   } else{
       printf("队列为空，无法展示队列中队头的元素");
   }
}
//输出队列中的队尾元素
void GetQueueRear(SeqQueue *s){
    DataType y=0;
    if(!EmptySeq(s)){
        y=s->data[s->rear-1];
        printf("队尾元素为%d\n",y);
    } else{
        printf("队列为空，无法展示队列中队头的元素");
    }
}

void main(){
   SeqQueue s;
   DataType x=0;
   int flag;
    InitSeqQueue(&s);
    flag=EmptySeq(&s);
    printf("------flag=%d------\n",flag);
    EnQueue(&s);
    flag=EmptySeq(&s);
    printf("----flag=%d-------\n",flag);
   // GetQueueFront(&s);
    GetQueueRear(&s);
    while (!EmptySeq(&s)){
        DeQueue(&s,&x);
        printf("出队元素:%d\t",x);
    }
}

