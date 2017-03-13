#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
int m,n,fa[1005];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct edges
{
	int f,t,v;
}e[100005];
inline bool cmp(edges a,edges b){return a.v<b.v;}
void krustal()
{
	LL ans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].f),y=find(e[i].t);
		if(x!=y)
		{
			ans+=e[i].v;
			fa[x]=y;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		e[i].f=read();
		e[i].t=read();
		e[i].v=read();
	}
	sort(e+1,e+m+1,cmp);
	krustal();
	return 0;
}
