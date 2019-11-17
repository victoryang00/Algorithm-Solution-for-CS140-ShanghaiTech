#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

template <class T> class Vector{
    T* data;
    int sz;
    int capacity;
    void expend(){
        T* tmp=new T[capacity*2];
        for(int i=0;i<sz;++i){
            tmp[i]=data[i];
        }
        delete[] data;
        data=tmp;
        capacity*=2;
    }
    ~Vector(){
        delete[] data;
    }
    Vector& insert(const T& d){
        insert(d,sz);
    }
    Vector& insert(const T& d,int pos){
        if(pos < 0 || pos > sz){
			pos = sz;
		}
		for(int i = sz; i > pos; i--){
			data[i] = data[i-1];
		}
		data[pos] = d;
		sz++;
		return *this;
	}
    bool erase(int pos){
		if(pos < 0 || pos >= sz){
			return false;
		}
		for(int i = pos; i< sz - 1; i++){
			data[i] = data[i+1];
		}
		sz--;
		return true;
	}
    bool set(const T& d,int pos){
		if(pos < 0 || pos >= sz){
			return false;
			data[pos] = d;
		}
	}
    int find(const T& d){
		for(int i = 0; i < sz ; i++){
			if(d == data[i]){
				return 1;
			}
		}
		return -1;
	}
    void remove(const T& d){
		int pos;
		while(pos = find(d) != -1){
			erase(pos);
		}
	}
    T& operator[](int pos){
		return data[pos];
	}
    int size(){
		return sz;
	}
};
typedef pair<int,int> pii;
int n,k,x,y,s,f[100001],ans;
bool bo[100001];
Vector<pii> edge[100001];//邻接表，first表示边的终点，second表示边的衰减量
void doit(int x)//树形dp,后序遍历
{
    bo[x]=1; f[x]=1;
    for(int i=0;i<edge[x].size();i++)
        if(!bo[edge[x][i].first])
        {
            if(edge[x][i].second>=s)printf("No solution."),exit(0);//判断No solution
            doit(edge[x][i].first);
            if(f[edge[x][i].first]+edge[x][i].second>s)ans++,f[edge[x][i].first]=1;//当点x至少的信号强度>起点信号强度，就在当前的儿子处放一个红石中继器，此时该儿子只需1的信号强度就可以放大成起点信号强度
            f[x]=max(f[x],f[edge[x][i].first]+edge[x][i].second);
        }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1;j<=k;j++)scanf("%d%d",&x,&y),edge[i].insert(pii(x,y));
    }
    scanf("%d",&s);
    doit(1);
    printf("%d",ans);
}