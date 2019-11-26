#include <iostream>
using namespace std;
const int INF = 99999999;
const int NMAX=2e2+5;
int a[NMAX*NMAX],e[NMAX][NMAX];
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
        sort(a,count);
        cout<<a[p-1];
        return 0 ;
}