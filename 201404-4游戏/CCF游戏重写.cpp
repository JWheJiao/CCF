#include<bits/stdc++.h>
#define jxy (x>0&&x<=n&&y>0&&y<=m)
using namespace std;
int n,m,t,ans,d[105][105][305],dp[105][105][305];
int main()
{
	cin>>n>>m>>t;
	while(t--)
	{
		int r,c,a,b; 
		cin>>r>>c>>a>>b;
		for(int i=a;i<=b;i++)
			d[r][c][i]=1;
	}
	dp[1][1][0]=1;
	if(n!=1&&m!=1)
	for(int k=1;;k++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(d[i][j][k])continue;
				int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
				for(int c=0;c<4;c++)
				{
					int x=i+xx[c],y=j+yy[c];
					if(jxy&&dp[x][y][k-1])dp[i][j][k]=1;
				}
			}
		if(dp[n][m][k])
		{
			ans=k;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
