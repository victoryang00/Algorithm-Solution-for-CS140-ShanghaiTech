#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 150001;
const int MAXM = 250001;
int cnt=0,u[MAXM],v[MAXM],w[MAXM],first[MAXN],next[MAXM];
int dis[MAXN],st,ans=0,n,fa[MAXN];
inline int qread(void){
    int x=0;
    char s;
    s=getchar();
    while(s>'9'||s<'0')
        s=getchar();
    while(s>='0'&&s<='9'){
        x*=10;
        x+=s-'0';
        s=getchar();
    }
    return x; 
}
inline void qwrite(int x){
    if(x>9){
    qwrite(x/10);
    }
    putchar(x%10+'0');
}
void addedge(int ux,int vx,int wx){
    ++cnt;
    u[cnt]=ux;
    v[cnt]=vx;
    w[cnt]=wx;
    next[cnt]=first[ux];
    first[ux]=cnt;
}
void dfs2(int x,int f){
    for(int i=first[x];i;i=next[i]){
        if(v[i]==f)
            continue;
        fa[v[i]]=w[i];
        dfs2(v[i],x);
        dis[x]=max(dis[v[i]]+w[i],dis[x]);
    }
    if(dis[x]+fa[x]>st){
        ans++;
        dis[x]=0;
        }
}
int main(){
    n=qread();
    int m=0;
    for(int i=1;i<=n;i++){
        int mid;
        mid=qread();
        for(int j=1;j<=mid;j++){
            int vx,wx;
            vx=qread();
            wx=qread();
            addedge(i,vx,wx);
            m=max(m,wx);
        }
    }
    st=qread();
    if(m>=st){
        printf("No solution.\n");
        return 0;
    }
    dfs2(1,1);
    qwrite(ans);
    return 0;
}