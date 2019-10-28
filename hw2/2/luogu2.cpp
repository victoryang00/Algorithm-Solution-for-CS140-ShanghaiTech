#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define re register int 
using namespace std;
const int MAX=2e4+5;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){if(A==B){B=(A=ss)+fread(ss,1,1<<17,stdin);if(A==B)return EOF;}return *A++;};
template<class T>inline void read(T&x){
    char c;re y=1;while(c=gc(),c<48||57<c)if(c=='-')y=-1;x=c^48;
    while(c=gc(),47<c&&c<58)x=(x<<1)+(x<<3)+(c^48);x*=y;
}
int n,cnt,w,sss,ans;
int fi[MAX],dis[MAX],fa[MAX];
struct hehe{
    int nx,nd,co;
}e[MAX*2];
void add(int a,int b,int c)
{
    e[++cnt]=(hehe){fi[a],b,c},fi[a]=cnt;
}
void dfs(int x,int fat)
{
    for(int v=fi[x];v;v=e[v].nx)
    if(e[v].nd!=fat)
    {
        fa[e[v].nd]=e[v].co;//fa[x]表示x点到他父亲的距离
        dfs(e[v].nd,x);
        dis[x]=max(dis[e[v].nd]+e[v].co,dis[x]);
    }
    if(dis[x]+fa[x]>w)ans++,dis[x]=0;
}
int main()
{
    read(n);
    for(int i=1;i<=n;i++)
    {
        int k;
        read(k);
        for(int j=1;j<=k;j++)
        {
            int b,c;
            read(b);read(c);
            add(i,b,c);
            sss=max(sss,c);
        }
    }
    read(w);
    if(sss>=w){cout<<"No solution.";return 0;}
    dfs(1,1);
    cout<<ans;
    return 0;
}