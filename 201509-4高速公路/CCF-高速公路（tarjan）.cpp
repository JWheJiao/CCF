#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
int dfn[MAXN],low[MAXN],wh[MAXN],m,n,ans,ct;
stack<int> s;
vector<int> e[MAXN];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
void dfs(int k)
{
	s.push(k);
	wh[k]=1;
	low[k]=dfn[k]=++ct;
	for(int i=0;i<e[k].size();i++)
		if(!dfn[e[k][i]])
		{
			dfs(e[k][i]);
			low[k]=min(low[k],low[e[k][i]]);
		}
		else if(wh[e[k][i]])low[k]=min(low[k],dfn[e[k][i]]);
	if(low[k]==dfn[k])
	{
		//printf("第%d个强连通分量：\n",ct);
		int tp=s.top(),cnt=1;
		//cout<<tp<<' ';
		wh[tp]=0;
		s.pop();
		while(tp!=k)
		{
			tp=s.top();
			//cout<<tp<<' ';
			wh[tp]=0;
			s.pop();
			cnt++;
		}
		//cout<<endl<<"个数为："<<cnt<<endl;
		ans+=(cnt*(cnt-1))/2;
	}
}
void tarjan()
{
	while(1)
	{
		int tp=0;
		for(int i=1;i<=n;i++)
			if(!dfn[i])
			{
				tp=i;
				break;
			}
		if(!tp)break;
		dfs(tp);
	}
	cout<<ans<<endl;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		e[x].push_back(y);
	}
	//memset(low,127/3,sizeof(low));
	tarjan();
	return 0;
} 
