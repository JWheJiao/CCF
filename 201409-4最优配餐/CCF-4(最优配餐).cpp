#include<bits/stdc++.h>
#define jxy (x>0&&x<=n&&y>0&&y<=n)
using namespace std;
typedef long long LL;
const int MAXN=1005;
LL tot=0;
int n,m,k,d,mp[MAXN][MAXN],tp[MAXN][MAXN],ans,dis[MAXN][MAXN];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
struct data
{
	int x,y,v;
	data(int a,int b,int c)
	{
		x=a;y=b;v=c;
	}
};
struct pt
{
	int x,y,d;
	pt(int a,int b,int c)
	{
		x=a;y=b;d=c;
	}
};
vector<data> e;
int dfs(int d,int a,int b)
{
	if(d>ans)return 0;
	//else if(tp[a][b]==2)return d;
	int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
	for(int i=0;i<4;i++)
	{
		int x=a+xx[i],y=b+yy[i];
		if(tp[x][y]==1||!jxy)continue;
		else if(tp[x][y]==2)return d;
		else
		{
			tp[x][y]==1;
			int k=dfs(d+1,x,y);
			if(k)return k;
			tp[x][y]=0;
		}
	}
	return 0;
}
int bfs(int a,int b)
{
	memcpy(tp,mp,sizeof(mp));
	queue<pt> q;
	vector<pt> v;
	q.push(pt(a,b,0));
	while(1)
	{
		pt t=q.front();
		q.pop();
		int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
		for(int i=0;i<4;i++)
		{
			int x=t.x+xx[i],y=t.y+yy[i];
			if(tp[x][y]==1||!jxy)continue;
			else if(tp[x][y]==2)
			{
				for(int j=0;j<v.size();j++)
					if((v[j].x-a)*(x-a)>0&&(v[j].y-b)*(y-b)>0)
						dis[v[j].x][v[j].y]=t.d-v[j].d;
				return t.d+1;
			}
			else if(tp[x][y]==3)v.push_back(pt(x,y,t.d+1));
			else 
			{
				q.push(pt(x,y,t.d+1));
				tp[x][y]=1;
			}
		}
	}
}
int main()
{
	queue<pt> q;
	n=read();m=read();k=read();d=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		q.push(pt(x,y,0));
		//mp[x][y]=2;
	}
	for(int i=1;i<=k;i++)
	{
		int x=read(),y=read(),v=read();
		if(!mp[x][y])
			mp[x][y]=2;
		dis[x][y]=v;
		//e.push_back(data(x,y,v));
	}
	for(int i=1;i<=d;i++)
	{
		int x=read(),y=read();
		mp[x][y]=1;
	}
	/*
	for(int i=0;i<e.size();i++)
	{
		ans=1;
		if(dis[e[i].x][e[i].y])
		{
			tot+=e[i].v*dis[e[i].x][e[i].y];
			continue;
		}
		memcpy(tp,mp,sizeof(tp));
		if(mp[e[i].x][e[i].y]==2)continue;
		while(1)
		{
			int k=dfs(1,e[i].x,e[i].y);
			if(k)
			{
				tot+=e[i].v*k;
				dis[e[i].x][e[i].y]=k; 
				break;
			}
			ans++;
		}
	}
	*/
	/*
	for(int i=0;i<e.size();i++)
	{
		if(mp[e[i].x][e[i].y]==2)continue;
		else if(dis[e[i].x][e[i].y])
		{
			tot+=dis[e[i].x][e[i].y]*e[i].v;
			continue;
		}
		int k=bfs(e[i].x,e[i].y);
		dis[e[i].x][e[i].y]=k;
		tot+=k*e[i].v;
	}
	*/
	while(!q.empty())
	{
		pt t=q.front();
		q.pop();
		int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
		for(int i=0;i<4;i++)
		{
			int x=t.x+xx[i],y=t.y+yy[i];
			if(mp[x][y]==1||!jxy)continue;
			else if(mp[x][y]==2)
			{
				tot+=(t.d+1)*dis[x][y];
				mp[x][y]=1;
				q.push(pt(x,y,t.d+1));
			}
			else 
			{
				q.push(pt(x,y,t.d+1));
				mp[x][y]=1;
			}
		}
	}
	cout<<tot<<endl;
	return 0;
}
