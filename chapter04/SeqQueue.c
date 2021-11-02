#include<stdio.h>
#define MaxSize 100 //���������������
typedef int DataType;//����DataTypeΪint����
typedef struct SeqQueue{
    DataType data[MaxSize];
    int rear;//��βָ��
    int front;//��ͷָ��
}SeqQueue;

//��ʼ������
void InitSeqQueue(SeqQueue *s){
    s->front=s->rear=0;
}
//�ж϶����Ƿ�Ϊ��
int EmptySeq(SeqQueue *s){
    if(s->rear==s->front){
        return 1; //�շ���1
    } else{
        return 0;
    }
}
//�ж϶����Ƿ�����
int FullQueue(SeqQueue *s){
    if((s->rear+1)%MaxSize==s->front){
        return 1; //������1
    } else{
        return 0;
    }
}
//Ԫ�������
void EnQueue(SeqQueue *s){
    DataType x = 0;
    //���ǰ�ж��Ƿ�����
    if(!FullQueue(s)){
        printf("��������Ҫ��ӵ�Ԫ��:");
        scanf("%d",&x);
        while (x!=9999){
            s->data[s->rear]=x;
            s->rear=(s->rear+1)%MaxSize;
            printf("��������Ҫ��ӵ�Ԫ��:");
            scanf("%d",&x);
        }
    } else{
        printf("��������������");
    }
}

//Ԫ�س�����   x������ӵ�Ԫ��
void DeQueue(SeqQueue *s,DataType *x){
    //����ǰ�ж��Ƿ��ѿ�
     if(!EmptySeq(s)){
         *x=s->data[s->front];
         s->front=(s->front+1)%MaxSize;
     } else{
         printf("�����ѿ�");
     }
}
//��������еĶ�ͷԪ��
void GetQueueFront(SeqQueue *s){
    DataType x=0;
   if(!EmptySeq(s)){
       x=s->data[s->front];
       printf("��ͷԪ��Ϊ%d\n",x);
   } else{
       printf("����Ϊ�գ��޷�չʾ�����ж�ͷ��Ԫ��");
   }
}
//��������еĶ�βԪ��
void GetQueueRear(SeqQueue *s){
    DataType y=0;
    if(!EmptySeq(s)){
        y=s->data[s->rear-1];
        printf("��βԪ��Ϊ%d\n",y);
    } else{
        printf("����Ϊ�գ��޷�չʾ�����ж�ͷ��Ԫ��");
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
        printf("����Ԫ��:%d\t",x);
    }
}

