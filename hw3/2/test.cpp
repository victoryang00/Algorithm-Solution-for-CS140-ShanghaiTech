#include <iostream>
using namespace std;
const int KMAX=400+5;
const int INF=99999999;
const int NMAX=2e2+5;
int a[KMAX][2];
int b[2][NMAX];
int c[KMAX*2];
int e[2*KMAX][2*KMAX];

int quicksort_k_small1_1(int a[], int l, int r, int k){
    if (l >= r) return a[l];
    int v = a[l];//基准

    //i，j左右分块的初始值, 要保证初始化时，俩个子数组都为空，即，数组右端索引<左端索引
    int i = l + 1;//a[l+1...i-1]>v
    int j = r;//a[j+1...r]<v

    while (true){
        while (i <= r && a[i] > v) ++i;//降序
        while (j >= l + 1 && a[j] < v) --j;
        if (i > j) break;//循环结束标志
        swap(a[i], a[j]);
        ++i;
        --j;
    }
    swap(a[l], a[j]);

    int th = r - k;//设定好 降序时 第k小的数 对应 的是 正序时的 第th大的数

    if (j == th) return j;
    if (j < th) return quicksort_k_small1_1(a, j + 1, r, k);
    else return quicksort_k_small1_1(a, l, j - 1, k);
}
int main(){
  int  a[]={2,1};
  cout<<quicksort_k_small1_1(a,0,2,1)<<'\n';
}