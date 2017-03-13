#include<bits/stdc++.h>
#define N 10010 
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
int n,m,path[100005];
bool ck[N][N];
vector<int> e[100005];
struct pt
{
	int v,o;
	pt(int x)
	{
		v=x;
		o=0;
	}
};
vector<pt> ee[100005];
int solve(int s,int k)
{
	for(int i=0;i<ee[s].size();i++)
		if(ee[s][i].v==k)return i;
}
int dfs(int d,int k)
{
	for(int i=0;i<e[k].size();i++)
	{
		//int x=solve(k,e[k][i]),y=solve(e[k][i],k);
		if(ck[k][e[k][i]])continue;
		path[d+1]=e[k][i];
		if(d==m)return 1;
		ck[k][e[k][i]]=1;
		ck[e[k][i]][k]=1;
		if(dfs(d+1,e[k][i]))return 1;
		ck[k][e[k][i]]=0;
		ck[e[k][i]][k]=0;
	}
	return 0;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if(e[x].size()==0)e[x].push_back(y);
		else e[x].insert(lower_bound(e[x].begin(),e[x].end(),y),y);
		if(e[y].size()==0)e[y].push_back(x);
		else e[y].insert(lower_bound(e[y].begin(),e[y].end(),x),x);
		//ee[x].push_back(pt(y));
		//ee[y].push_back(pt(x)); 
	}
	path[1]=1;
	if(dfs(1,1))
	{
		printf("%d",path[1]);
		for(int i=2;i<=m+1;i++)printf(" %d",path[i]);
		cout<<endl;
	}
	else puts("-1");
	return 0;
}
