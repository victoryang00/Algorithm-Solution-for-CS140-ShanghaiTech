#include <iostream>
using namespace std;
const int INF = 99999999;
const int NMAX=2e2+5;
int a[NMAX*NMAX],e[NMAX][NMAX];
int quicksort_k_small1_1(int a[], int l, int r, int k)//从大到小排序
{
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

    if (j == th) return a[j];
    if (j < th) return quicksort_k_small1_1(a, j + 1, r, k);
    else return quicksort_k_small1_1(a, l, j - 1, k);
}

int main()
{
        int n , m ,p, t1 , t2 , t3,count=0;
        cin>>n>>m>>p; 
        for(int i = 1 ; i <= n ; i ++) 
        {
                for(int j = 1 ; j <= n ; j ++)
                {
                        if(i == j)
                                e[i][j] = 0 ;
                        else
                                e[i][j] = INF;
                }
        }
        for(int i = 1 ; i <= m ; i ++)
        {
                cin>>t1>>t2>>t3;
                e[t1][t2] = t3;
                e[t2][t1] = t3;
        }
        for(int k = 1 ; k <= n ; k ++)
        {
                for(int i = 1 ; i <= n ; i ++)
                {
                        for(int j = 1 ; j <= n ; j ++)
                        {
                                if(e[i][j] > e[i][k] + e[k][j])
                                        e[i][j] = e[i][k] + e[k][j];
                        }
                }
        }
        for(int i = 1 ; i <= n ; i ++)
        {
                for(int j = 1 ; j < i ; j ++)
                {
                    if (e[i][j]!=0 &&e[i][j]!=INF){
                        a[count]=e[i][j];
                        count++;
                    }
                }
        }

        // for(int i = 1 ; i <= n ; i ++)
        // {
        //         for(int j = 1 ; j <= n ; j ++)
        //         {
        //                 printf("%3d",e[i][j]);
        //         }
        //         cout<<endl;
        // }
        // for (int i = 0 ; i <count ; i ++)
        //     cout<<a[i]<<endl;
        cout<<quicksort_k_small1_1(a,0,count-1,p+1)<<endl;
        return 0 ;
}