#include <iostream>
 
using namespace std;
 
void sort(int array[],int len)
{
    int i = 0, j = 0;
    int temp = 0;
    for (i = 0; i < len-1; i++)
    {
        for (j = i+1; j < len; j++)
        {
            if (array[j]<array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
 
int main()
{
    int i = 0;
    int array[] = {5,3,6,9,4,2};
    int len = 6;
    cout<<len<<endl;
    printf("打印之前的数据为:");
    for (i = 0; i < len; i++)
    {
        cout<<array[i]<<"  ";
    }
    sort(array,len);
 
    printf("\n 排序之后的数组为:");
    for (i = 0; i < len; i++)
    {
        cout<<array[i]<<"  ";
    }
    printf("\n");
    return 0;
}