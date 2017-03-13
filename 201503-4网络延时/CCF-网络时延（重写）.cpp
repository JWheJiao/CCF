#include<bits/stdc++.h>
using namespace std;
const int MAXN=20005;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
vector<int> dis[MAXN];
int m,n,s,wh[MAXN],d[MAXN];
int bfs(int k)
{
	int ans=0;
	memset(wh,0,sizeof(wh));
	wh[k]=1;
	memset(d,0,sizeof(d));
	queue<int> q;
	q.push(k);
	while(!q.empty())
	{
		int tp=q.front();
		q.pop();
		for(int i=0;i<dis[tp].size();i++)
		{
			if(wh[dis[tp][i]])continue;
			q.push(dis[tp][i]);
			wh[dis[tp][i]]=1;
			d[dis[tp][i]]=d[tp]+1;
			if(d[tp]+1>ans)
			{
				//printf("增加1步，从%d到%d\n",tp,dis[tp][i]);
				ans=d[tp]+1;
				s=dis[tp][i];
			}
		}
	}
	return ans;
}
int main()
{
	n=read();
	m=read();
	for(int i=2;i<=m+n;i++)
	{
		int tp=read();
		dis[tp].push_back(i);
		dis[i].push_back(tp);
	}
	bfs(1);
	//cout<<s<<endl;
	printf("%d\n",bfs(s));
	//cout<<s<<endl;
	return 0;
}
