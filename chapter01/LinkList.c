#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct LinkList{
    ElementType  data;
    struct LinkList *next;
}LNode,*LinkList;

//初始化单链表
LinkList InitList(){
    LinkList L;
    L=(LinkList) malloc(sizeof(LinkList));
    L->next=NULL;
    return L;
}

//头插法建立单链表
LinkList CreateLinkList(LinkList head){
    LNode *s;
    ElementType x;
    printf("input data(head insert):");
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        s->next=head->next;
        head->next=s;
        printf("input data(head insert):");
        scanf("%d",&x);
    }
    return head;
}

//尾插法建立单链表
LinkList CreateList_tail(LinkList head){
    ElementType x;
    LNode *s;
    LNode *last;
    last=head;
    printf("input data(tail insert):");
    scanf("%d",&x);
    while (x!=9999){
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        s->next=NULL;
        last->next=s;
        last=s;
        printf("input data(tail insert):");
        scanf("%d",&x);
    }
    return head;
}
//求表长
int ListLength(LinkList head){
    LNode *p=head->next;
    int length=0;
    while (p!=NULL){
        length++;
        p=p->next;
    }
    return length;
}

//遍历输出单链表中所有的元素
void ShowLinkList(LinkList L){
    LinkList p;
    p=L->next;
    printf("\noutput data:");
    while (p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

//按照位置插入元素
void LocateInsert(LinkList head,int location,ElementType data){
    int index=0,length= ListLength(head); //当前指针指向的元素位置
    LNode *s; //定义新的节点，用于存放要插入的元素
    LNode *current=head;//
    if(location<1 || location>length+1){
        printf("input data illegal!!!");
        exit(0);
    }
    while (index<location-1 && current!=NULL){
        current=current->next;
        index++;
    }
    if(current!=NULL){
        s=(LNode *) malloc(sizeof (LNode));
        s->data=data;
        s->next=current->next;
        current->next=s;
    }
}

//按照序号查找元素
void SearchElementByIndex(LinkList head,int index){
    LNode *p=head->next;
    int currentIndex=1;
    if(index<0 || index> ListLength(head)){
        printf("index is illegal!!!");
        exit(0);
    }
    while (p!=NULL && currentIndex<index){
        currentIndex++;
        p=p->next;
    }
    if(currentIndex==index){
        printf("\nNO %d element data is %d",index,p->data);
    }
}

//按照值查找元素在链表中的位置
int SearchElementByData(LinkList head,ElementType data){
    LNode *p=head->next;
    int index=1;
    while (p!=NULL && p->data!=data){
        p=p->next;
        index++;
    }
    if(p==NULL){
        printf("\ndata is not in LinkList!!!");
    } else{
        printf("\ndata %d index is %d",data,index);
    }
    return index;
}

//按照位置删除元素
void DeleteElementByIndex(LinkList head,int location){
    LNode *p=head;
    LNode *deleteNode;
    int index=0;//记录当前指针指向元素的下标
    if(location<1 || location> ListLength(head)){
        printf("\ndelete element is illegal!!!");
    }
    while (p!=NULL && index<location-1){
        p=p->next;
        index++;
    }
    if(p!=NULL && index==location-1){
        deleteNode=p->next;
        p->next=deleteNode->next;
        free(deleteNode);
        printf("delete success!!!!");
    }
}

//按照元素值删除元素
void DeleteElementByData(LinkList head,ElementType data){
    LNode *p=head->next;
    int index=SearchElementByData(head,data);
    DeleteElementByIndex(head,index);
}

//求所有元素之和（平均值）
void getAverage(LinkList head){
    LNode *p=head->next;
    int sum=0,average=0;
    while (p!=NULL){
        sum=sum+(p->data);
        p=p->next;
    }
    average=sum/ ListLength(head);
    printf("\naverage is:%d",average);
}

//找出所有元素中最大（小）的数
void getMaxData(LinkList head){
    LNode *p=head->next;
    int max=p->data;
    while (p!=NULL){
        if((p->data)>max){
            max=p->data;
        }
        p=p->next;
    }
    printf("max element data is %d",max);
}

//按从小到大（从大到小）的顺序排序(简单选择排序)
void sortByValue(LinkList head){
    LNode *p, *q;
    int temp;
    p = head->next;
    while(p)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}
//去除单链表中相同的元素
void RemoveEqualValue(LinkList head){
    LNode *p,*s,*q;
    p=head->next;
    if(p==NULL)
        return;
    while(p->next!=NULL)
    {
        q=p;
        while(q->next!=NULL)				//固定p所指结点，向后遍历，寻找与之数据域相同的结点
        {
            if(q->next->data==p->data)	//在这里将q->next所指的结点存放数据与p作比较
            {
                s=q->next;
                q->next=s->next;
                free(s);
            } else
                q=q->next;
        }
        p=p->next;
    }
}

//翻转链表
void reverse(LinkList head){
    /*p指向要反转单链表的第一个元素*/
    LNode *p=head->next,*s;
    /*head单独成为一个新的链表*/
    head->next=NULL;
    while(p)
    {
        s=p;
        p=p->next;
        /*头插法建立单链表的过程*/
        s->next=head->next;
        head->next=s;
    }
}

int main(){
    LinkList head;
    //初始化单链表
    head=InitList();
    //头插法建立单链表
    //CreateLinkList(head);
    //尾插法建立单链表
    CreateList_tail(head);
    //输出链表中的所有元素
    ShowLinkList(head);
    //printf("%d",ListLength(head)) ;
    printf("\n-------------------------------\n");
    //插入元素
//    LocateInsert(head,1,6);
//    ShowLinkList(head);

    //按位置查找元素
    //SearchElementByIndex(head,1);

    //按照元素值查找元素的下标
    //SearchElementByData(head,9);

    //按照位置删除元素
//    DeleteElementByIndex(head,2);
//    ShowLinkList(head);

    //按照元素值来删除元素
//    DeleteElementByData(head,9);
//    ShowLinkList(head);

    printf("\n-------------------------------\n");
    //查找单链表中最大的元素
    //getMaxData(head);
    //计算单链表中所有元素的平均值
    //getAverage(head);


    printf("\n-----------------------------------\n");
    //把单链表中的元素按照从小到大排序
//    sortByValue(head);
//    ShowLinkList(head);
//
//     //删除单链表中相同元素
//    RemoveEqualValue(head);
//    ShowLinkList(head);

//反转链表
    reverse(head);
    ShowLinkList(head);

}

