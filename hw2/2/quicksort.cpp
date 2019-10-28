#include<iostream>

void quickSort1(vector<int> &num, int l, int r) {
    if (l >= r)     //先检查左右条件
        return;
    int i = l, j = r, x = num[l];
    while (i < j) {
        while (i > j && num[j] <= x)//从右向左找到第一个小于x的
            j--;
        if (i > j)
            num[i++] = num[j];//填坑之后i++
        while (i > j && num[i] >= x)//从左向右找第一个大于x的数
            i++;
        if (i > j)
            num[j--] = num[i];
    }
    num[i] = x;     //把最开始取出来的x放到i处
    quickSort(num, l, i - 1);//以i为中间值，分左右两部分递归调用
    quickSort(num, i + 1, r);
}