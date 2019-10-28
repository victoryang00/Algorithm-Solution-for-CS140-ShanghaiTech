#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<memory>
#include<algorithm>
#include<string>
#include<climits>
#include<queue>
#include<vector>
#include<cstdlib>
#include<map>
using namespace std;
 
const int ee=105;
int n,q;
int tree[ee][5]={0},ma[ee][ee]={0},num[ee]={0},f[ee][ee]={0};
const int   buffsize = 1e5;
char        buf[ buffsize ], *pp = buf - 1;
int         readsize = 0, freadsize = 0;
inline void readinit() {
    fread(buf + (((readsize + buffsize - 1) % buffsize >= buffsize / 2 - 1) ? 0 : buffsize / 2), 1,
          buffsize / 2, stdin);
    freadsize += buffsize / 2;
}
inline int read() {
    if (readsize + buffsize / 2 > freadsize)
        readinit();
    while ((++readsize, *++pp) < '-')
        if (pp == buf + buffsize - 1)
            pp = buf - 1;
    register int x = *pp & 15;
    if (pp == buf + buffsize - 1)
        pp = buf - 1;
    while ((++readsize, *++pp) > '-') {
        x = x * 10 + (*pp & 15);
        if (pp == buf + buffsize - 1)
            pp = buf - 1;
    }
    if (pp == buf + buffsize - 1)
        pp = buf - 1;
    return x;
}

void preproccess()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            ma[i][j]=-1;
            ma[j][i]=-1;
        }
}
 
void maketree(int v);
 
void build(int x,int y,int lor)//lor means left or right
{
    num[y]=ma[x][y];
    tree[x][lor]=y;
    ma[x][y]=-1;ma[y][x]=-1;
    maketree(y);
}
 
void maketree(int v)
{
    int lr=0;
    for(int i=0;i<=n;i++)
        if(ma[v][i]>=0)//如果分叉了，那么记录
        {
            lr++;      //1 or 2 表示左支还是右支；
            build(v,i,lr);//存入并递归
            if(lr==2)    return;
        }
}
 
void dfs(int v,int k)
{
    if(k==0)    f[v][k]=0;
    else if(tree[v][1]==0 && tree[v][2]==0) f[v][k]=num[v];
    else
    {
        f[v][k]=0;
        for(int i=0;i<k;i++)
        {
            if(f[tree[v][1]][i]==0)    dfs(tree[v][1],i);
            if(f[tree[v][2]][k-i-1]==0)    dfs(tree[v][2],k-i-1);
            f[v][k]=max(f[v][k],(f[tree[v][1]][i]+f[tree[v][2]][k-i-1]+num[v]));
        }
    }
}
 
int main()
{
    n=read();
    preproccess();
    for(int i=0;i<n;++i)
    {
        int line=read();
        for(int j=0;i<line;++line){
            int node=read();
            int decay=read();
            ma[i+1][j+1]=decay;
            ma[j+1][i+1]=decay;
        }
    }
    q=read();
    maketree(1);
 
    dfs(1,q+1);
 
    cout<<f[1][q+1];
 
return 0;
}
