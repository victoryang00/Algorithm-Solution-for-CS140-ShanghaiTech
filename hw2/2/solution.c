#include <stdio.h>
#include <stdlib.h>

int * array=NULL;//存放栈元素的数组
int count=0;//当前栈的元素个数

//初始化栈
void init_stack(int size)
{

    array=(int *)malloc(sizeof(int)*size);
    if(!array)
    {
        printf("创建栈失败");
        return ;
    }


}
//向栈中压入元素
void push( int val)
{
    array[count++]=val;
}
//输出栈顶元素
int peek()
{
    if(length_stack()==0)
    {
         printf("此栈为空栈\n");
         return 0;
    }

    return array[count-1];
}
//输出栈顶顶顶元素并且删除栈顶元素
int pop()
{
    int length=length_stack();
    if(length==0)
    {
        printf("已经到栈底啦\n");
        return -1;
    }
    int val=peek();
    count--;
    return val;
}
//求栈的长度
int length_stack()
{
    return count;
}
//打印栈的信息
void print_stack()
{
    int i=length_stack()-1;
    while(i>=0)
    {
        printf("%d   ",array[i--]);
    }
}
