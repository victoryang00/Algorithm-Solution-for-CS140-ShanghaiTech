#include <iostream>
using namespace std;
const int KMAX=400+5;
const int INF=99999999;
const int NMAX=2e2+5;
int a[NMAX];
int b[1][NMAX];
int c[2][NMAX];
int e[2*KMAX][2*KMAX];
int p[KMAX];
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
int* sort1(int array[],int len,int kt)//Time complexity k*n
{
    int* tmp;
    for(int i=0;i<len;i++)
        tmp[i]=i;
    int i = 0, j = 0;
    int temp = 0;
    for (i = 0; i < kt-1; i++)
    {
        for (j = i+1; j < len; j++)
        {
            if (array[j]<array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                temp=tmp[i];
                tmp[i]=tmp[j];
                tmp[i]=temp;
            }
        }
    }
    return tmp;
}
int main(){
    int n,m,k,count=0;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){//输入
        cin>>b[0][i]>>b[1][i]>>a[i];
    }
    if(m>400){int* dd=sort1(a,m,401);n=2*k;m=k;}else{int* dd=sort1(a,m,m);}
    int temp;
    for(int i=1;i<=n;i++){
        c[2][i]=a[dd[i]];
        c[0][i]=b[0][dd[i]];
        c[1][i]=b[1][dd[i]];
    }
    for(int i = 1 ; i <= n ; i ++)//初始化数组
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
        e[c[0][i]][c[1][i]] = c[2][i];
        e[c[1][i]][c[0][i]] = c[2][i];
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
                p[count]=e[i][j];
                count++;
            }
        }
    }
    sort(p,count);
    cout<<p[k-1];
    return 0;
}