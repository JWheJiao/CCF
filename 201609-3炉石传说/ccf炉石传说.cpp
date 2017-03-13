#include<bits/stdc++.h>
#define go(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
struct sc
{
	int h,a,p;
	sc(int k,int b,int c)
	{
		p=k;
		h=c;
		a=b;
	}
};
vector<sc> v[2];
int h[2]={30,30},cur=1;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string op;
		cin>>op;
		if(op=="summon")
		{
			int p,heal,a;
			cin>>p>>heal>>a;
			v[cur].insert(v[cur].begin()+p-1,sc(p,heal,a));
		}
		else if(op=="attack")
		{
			int a,d;
			cin>>a>>d;
			if(d!=0)
			{
				v[cur][a-1].h=v[cur][a-1].h-v[!cur][d-1].a;
				v[!cur][d-1].h=v[!cur][d-1].h-v[cur][a-1].a;			
				if(v[!cur][d-1].h<=0)v[!cur].erase(v[!cur].begin()+d-1);
				if(v[cur][a-1].h<=0)v[cur].erase(v[cur].begin()+a-1);
			}
			else
			{
				h[!cur]-=v[cur][a-1].a;
			}
		}
		else if(op=="end") 
			cur=!cur;
	}

	if(h[0]>0&&h[1]>0)cout<<0<<endl;
	else if(h[0]<=0)cout<<1<<endl;
	else if(h[1]<=0)cout<<-1<<endl;
	cout<<h[1]<<endl;
	cout<<v[1].size();
	go(i,1,v[1].size())
	cout<<' '<<v[1][i-1].h;
	cout<<endl;
	cout<<h[0]<<endl;
	cout<<v[0].size();
	go(i,1,v[0].size())
	cout<<' '<<v[0][i-1].h;
	cout<<endl;
	return 0;
}
