#include<iostream>
using namespace std;
#define N 101
#define M 101

char a[N][M];

int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}else
	{
		return y;
	}
}
int min(int x,int y)
{
	if(x<y)
	{
		return x;
	}else
	{
		return y;
	}
}

void paintline(int x1,int y1,int x2,int y2)
{
	if(x1==x2)
	{
		for(int i=min(y1,y2);i<=max(y1,y2);i++)
		{
			if(a[i][x1]!='-')
			{
				a[i][x1]='|';
			}else
			{
				a[i][x1]='+';
			}
			
		}
	}
	if(y1==y2)
	{
		for(int i=min(x1,x2);i<=max(x1,x2);i++)
		{
			if(a[y1][i]!='|')
			{
				a[y1][i]='-';
			}else
			{
				a[y1][i]='+';
			}
			
		}
	}
}

void filled(int x,int y,char c,int m,int n)
{
	if((a[y][x+1]!='|'&&a[y][x+1]!='-'&&a[y][x+1]!='+')&&x+1<m&&a[y][x+1]!=c)
	{
		a[y][x+1]=c;
		filled(x+1,y,c,m,n);
	}
	if((a[y][x-1]!='|'&&a[y][x-1]!='-'&&a[y][x-1]!='+')&&x-1>=0&&a[y][x-1]!=c)
	{
		a[y][x-1]=c;
		filled(x-1,y,c,m,n);
	}
	if((a[y+1][x]!='|'&&a[y+1][x]!='-'&&a[y+1][x]!='+')&&y+1<n&&a[y+1][x]!=c)
	{
		a[y+1][x]=c;
		filled(x,y+1,c,m,n);
	}
	if((a[y-1][x]!='|'&&a[y-1][x]!='-'&&a[y-1][x]!='+')&&y-1>=0&&a[y-1][x]!=c)
	{
		a[y-1][x]=c;
		filled(x,y-1,c,m,n);
	}
}


int main()
{
	int m,n,q,i,j;
	cin>>m>>n>>q;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j]='.'; 
		}
	}
	for(i=0;i<q;i++)
	{
		int t,x1,x2,y1,y2;
		char c;
		cin>>t;
		if(t==1)
		{
			cin>>x1>>y1>>c;
			filled(x1,y1,c,m,n);
		}
		if(t==0)
		{
			cin>>x1>>y1>>x2>>y2;
			paintline(x1,y1,x2,y2);
		}
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
