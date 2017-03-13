#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll n,tot=0;
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
		for(int j=3;j<=n;j++)
		{
			if(j==i||(i==2&&j==3))continue;
			//printf("¿ªÊ¼:i=%d,j=%d\n",i,j);
			int ans=1;
			for(int k=2;k<min(i,j);k++)
				ans=(ans*2)%mod;
			if(i>j)
				ans--; 
			for(int k=min(i,j)+1;k<max(i,j);k++)
				ans=(ans*2)%mod;
			if(j>i)
				ans--;
			for(int k=max(i,j)+1;k<=n;k++)
				ans=(ans*2)%mod;
			tot=(tot+ans)%mod;
			//if(tot>mod)printf("wtf\n");
			//cout<<ans<<"   tot="<<tot<<endl;
			//printf("i=%d,j=%dÊ±tot=%lld,ans=%lld\n",i,j,tot,ans);
		}
	cout<<tot<<endl;
	return 0;
}
