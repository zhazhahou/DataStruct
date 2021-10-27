#include<stdio.h>
#include<stdlib.h>
/*    define后面不用加逗号
 * C语言中，可以用 #define 定义一个标识符来表示一个常量。
 * 其特点是：定义的标识符不占内存，只是一个临时的符号，预编译后这个符号就不存在了。
预编译又叫预处理。预编译不是编译，而是编译前的处理。
 这个操作是在正式编译之前由系统自动完成的。
 #define 和 #include 一样，也是以“#”开头的。凡是以“#”开头的均为预处理指令，#define也不例外。
 宏定义 #define 一般都写在函数外面，与 #include 写在一起。当然，
 写在函数里面也没有语法错误，但通常不那么写。#define 的作用域为自 #define
 那一行起到源程序结束。如果要终止其作用域可以使用 #undef 命令
 * */
#define MaxSize 100
typedef int DataType;
typedef struct SeqStack{
    DataType data[MaxSize];
    int top;
}SeqStack;
void InitStack(SeqStack *s){
    s->top=-1;
}
int EmptyStack(SeqStack *s){
    int flag;
    if(s->top==-1)
        flag=1;//1代表栈为空
    else
        flag=0;//0代表栈非空
    return flag;
}
int Push(SeqStack *s,DataType x){
    int flag;
    if(s->top==MaxSize-1){
        flag=1;//代表进栈失败
    } else{
        s->data[++s->top]=x;
        flag=0;
    }
    return flag;
}

int Pop(SeqStack *s,DataType *x){
    int flag;//flag标致位
    if(s->top==-1){
        flag=-1;
    } else{
        *x=s->data[s->top--];
        flag=0;
    }
    return flag;
}
int GetTop(SeqStack *s,DataType *x){
    int flag;
    if(s->top==-1){
        flag=0;//栈为空，无栈顶元素
    } else
    {
        *x=s->data[s->top];
        flag=1;
    }
    return flag;
}
int main(){
    int x;
   SeqStack s;
    InitStack(&s);
    Push(&s,5);
    Push(&s,6);
    GetTop(&s,&x);
    printf("%d",x);
    return 0;
}




















