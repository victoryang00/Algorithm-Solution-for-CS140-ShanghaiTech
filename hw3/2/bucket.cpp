#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// extern void quick_sort(int a[], int p, int q);/* not necessary */
struct barrel {
    int node[10];
    int count;/* the num of node */
};
 
void bucket_sort(int data[], int size)
{
    int max, min, num, pos;
    int i, j, k;
    struct barrel *pBarrel;
 
    max = min = data[0];
    for (i = 1; i < size; i++)
    {
        if (data[i] > max)
            max = data[i];
         else if (data[i] < min)
            min = data[i];
    }
    num = (max - min + 1) / 10 + 1;
    pBarrel = (struct barrel*)malloc(sizeof(struct barrel) * num);
    memset(pBarrel, 0, sizeof(struct barrel) * num);
 
    /* put data[i] into barrel which it belong to */
    for (i = 0; i < size; i++)
    {
        k = (data[i] - min + 1) / 10;/* calculate the index of data[i] in barrel */
        (pBarrel + k)->node[(pBarrel + k)->count] = data[i];
        (pBarrel + k)->count++;
    }
 
    pos = 0;
    for (i = 0; i < num; i++)
    {
        quick_sort((pBarrel+i)->node, 0, (pBarrel+i)->count);/* sort node in every barrel */
        for (j = 0; j < (pBarrel+i)->count; j++)
        {
            data[pos++] = (pBarrel+i)->node[j];
        }
    }
    free(pBarrel);
}

int main(){
    int a[]={1123,123,12,123,123,1,133,42};
    bucket_sort(a,8);
    for (int i=0;i<8;i++){
        cout<<a[i];
    }
}