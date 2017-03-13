#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,k,r,cnt,ck[205],ans;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
struct pt
{
	int x,y,v;
	pt(){} 
	pt(int a,int b)
	{
		x=a;y=b;	
	}
}d[205];
int check(pt a,pt b)
{
	if(abs((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))>r*r)return 0;
	return 1;
}
LL cl(pt a,pt b)
{
	return abs((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int dfs(int deep,int u,int c)
{
	LL dis=(ans-deep)*(ans-deep)*r*r;
	if(cl(d[2],d[u])>dis||deep>ans)return 0;
	if(deep==ans&&c<=k&&u==2)return 1;
	for(int i=1;i<=n+m;i++)
	{
		if(ck[i])continue;
		if(check(d[u],d[i]))
		{
			ck[i]=1;
			int t;
			if(i>n)
				t=dfs(deep+1,i,c+1);
			else t=dfs(deep+1,i,c);
			if(t)return 1;
			ck[i]=0;
		}
	}
	return 0;
}
int main()
{
	n=read();
	m=read();
	k=read();
	r=read();
	for(int i=1;i<=n+m;i++)
	{
		int x=read(),y=read();
		d[++cnt]=pt(x,y);
	}
	while(1)
	{
		memset(ck,0,sizeof(ck));
		ck[1]=1;
		if(dfs(0,1,0))
			break;
		ans++;
	}
	cout<<ans-1<<endl;
	return 0;
}
