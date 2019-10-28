
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define INF 0x3f3f3f3f
#define mem(vis,a) memset(vis,a,sizeof(vis))
#define bug puts("**********");
#define N 100100
 
using namespace std;
struct node
{
    int id;
    LL sum;
    friend bool operator <(node p1,node p2)
    {
        if(p1.sum!=p2.sum)
         return p1.sum>p2.sum;
        return p1.id<p2.id;
    }
}p[N];
template <class T>
class Vector
{
private:
	T* data;
	int sz;
	int capacity;
	void expend()
	{
		T* tmp = new T[capacity*2];
		for (int i = 0; i < sz; i++)
		{
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
		capacity *= 2;

	}
public:
	explicit Vector(int size = 5):sz(),capacity(size)
	{
		data = new T[size];
	}
	~Vector()
	{
		delete[] data;
	}

	friend ostream& operator<<(ostream& o,const Vector &v)
	{
		for (int i = 0; i< v.sz; i++)
		{
			o << v.data[i] << ' ';
		}
	return 0;
	}

	//插入一个元素到集合
	Vector& insert(const T& d)
	{
/*
		if(sz >= capacity)
		{
			expend();
		}
		data[sz++] = d;
		return *this;
*/
		insert(d,sz);
	}
	
	//在指定的位置插入元素
	Vector& insert(const T& d,int pos)
	{
		//超出范围时，放到最后一个位置
		if(pos < 0 || pos > sz)
		{
			pos = sz;
		}
		for(int i = sz; i > pos; i--)
		{
			data[i] = data[i-1];
		}
		data[pos] = d;
		sz++;
		return *this;
		
	}

	//删除指定位置的元素
	bool erase(int pos)
	{
		if(pos < 0 || pos >= sz)
		{
			return false;
		}
		for(int i = pos; i< sz - 1; i++)
		{
			data[i] = data[i+1];
		}
		sz--;
		return true;
	
	}

	//修改指定位置的元素
	bool set(const T& d,int pos)
	{
		if(pos < 0 || pos >= sz)
		{
			return false;
			data[pos] = d;
		}
	}

	//查找集合中是否存在指定的元素，返回这个元素的下标，如果未能找到
	int find(const T& d)
	{
		for(int i = 0; i < sz ; i++)
		{
			if(d == data[i])
			{
				return 1;
			}
		}
		return -1;
	}

	//删除所有等于d的数据元素
	void remove(const T& d)
	{
		int pos;
		while(pos = find(d) != -1)
		{
			erase(pos);
		}
	}

	//源代码不全，无法得知out_of_range 到底是怎么定义的
	//返回指定下表元素的引用
	T& at(int pos) throw(out_of_range)
	{
		if (pos < 0 || pos >= sz)
		{
			throw out_of_range("out of index");
		}
		return data[pos];
	}

	//下标运算
	T& operator[](int pos)
	{
		return data[pos];
	}

	//返回集合中的元素个数
	int size()
	{
		return sz;
	}

};
Vector<int>vec[N];
int n,m;
int vis[N];
LL val[N];
LL a[N];

LL DFS(int x)    ///构建出树的个点到根的权值 ，减枝==记忆化搜索
{
    if(vis[x])return p[x].sum;
    p[x].sum=val[x];
    vis[x]=1;
    p[x].id=x;
    for(int i=0;i<vec[x].size();i++)
    {
        p[x].sum+=DFS(vec[x][i]);
    }
    return p[x].sum;
}
LL DFS2(int x)   
{
    if(vis[x])return 0;
    LL sum=val[x];
    vis[x]=1;
    for(int i=0;i<vec[x].size();i++)
    {
        sum+=DFS2(vec[x][i]);
    }
    return sum;
}
void quickSort(vector<int> &num, int l, int r) {
    if (l >= r)     //先检查左右条件
        return;
    int i = l, j = r, x = num[l];
    while (i < j) {
        while (i < j && num[j] >= x)//从右向左找到第一个小于x的
            j--;
        if (i < j)
            num[i++] = num[j];//填坑之后i++
        while (i < j && num[i] <= x)//从左向右找第一个大于x的数
            i++;
        if (i < j)
            num[j--] = num[i];
    }
    num[i] = x;     //把最开始取出来的x放到i处
    quickSort(num, l, i - 1);//以i为中间值，分左右两部分递归调用
    quickSort(num, i + 1, r);
}
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
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        mem(vec,0);
 
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        scanf("%lld",&val[i]);
 
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            vec[y].push_back(x);   ///反向建树
        }
        mem(vis,0);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])   ///减枝
            DFS(i);
        }
        mem(a,0);    ///防止m>num 后遗留上次的算数值
        mem(vis,0);
        sort(p+1,p+n+1);
 
        int num=0;
        for(int i=1;i<=n;i++)
        {
           // if(!vis[p[i].id])  ///不要加这句话否则会使 m>num;
           // {
              a[num++]=DFS2(p[i].id);
            //}
        }
 
        sort(a,a+num,cmp);
        LL ans=0;
        for(int i=0;i<m;i++)
           ans+=a[i];
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}