#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
int hs[5003][5003],ans,n,q,mxx=0,mnx=0x7fffffff,mxy=0,mny=0x7fffffff,r;
vector<int> x[300005];
vector<int> y[300005];
int solve()
{
	for(int i=mnx;i<=mxx;i++)
	{
		if(x[i].size()/2<ans||x[i].size()==0)continue;
		for(int j=mny;j<=mxy;j++)
		{
			if(y[j].size()/2<ans||y[j].size()==0)continue;
			int tp=0,ax=lower_bound(y[j].begin(),y[j].end(),i)-y[j].begin(),ay=lower_bound(x[i].begin(),x[i].end(),j)-x[i].begin();
			if(x[i][ay]!=j&&ay!=x[i].size())
			{
				ax=ax<y[j].size()-ax?ax:y[j].size()-ax;
				ay=ay<x[i].size()-ay?ay:x[i].size()-ay;
				tp=min(ax,ay);
				if(tp>ans)
				{
					ans=tp;
					r=1;
				}
				else if(tp==ans)
					r++;
			}
		}	
	}
}
int main()
{
	n=read();q=read();
	while(n--)
	{
		int x1=read(),y1=read();
		if(x1>mxx)mxx=x1;
		if(x1<mnx)mnx=x1;
		if(y1>mxy)mxy=y1;
		if(y1<mny)mny=y1;
		x[x1].insert(lower_bound(x[x1].begin(),x[x1].end(),y1),y1);
		y[y1].insert(lower_bound(y[y1].begin(),y[y1].end(),x1),x1);
	}
	solve();
	if(q==1)cout<<ans<<endl;
	else cout<<r<<endl;
	return 0;
} 
