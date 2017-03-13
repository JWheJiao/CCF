#include<bits/stdc++.h>
using namespace std;
int a,b,c,k1,y2,m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int y)
{
	if(y%400==0||(y%4==0&&y%100!=0))return true;
	return false;
}
int solve(int y,int mt)
{
	int d=0;
	for(int i=1850;i<y;i++)
		if(check(i))d+=366;
		else d+=365;
	for(int i=1;i<mt;i++)
		d+=m[i];
	if(mt>2&&check(y))d++;
	if((d+2)%7==0)return 7;
	else return (d+2)%7;
}
int main()
{
	cin>>a>>b>>c>>k1>>y2;
	for(int i=k1;i<=y2;i++)
	{
		int k=solve(i,a),ans;
		if(k<=c)ans=(b-1)*7+c-k+1;
		else ans=b*7+c-k+1;
		if(check(i)&&a==2&&ans<=29||ans<=m[a])
		{
			/*
			if(a<10&&ans<10)cout<<i<<"/0"<<a<<"/0"<<ans<<endl;
			else if(a<10&&ans>=10)cout<<i<<"/0"<<a<<"/"<<ans<<endl;
			else if(a>=10&&ans<10)cout<<i<<"/"<<a<<"/0"<<ans<<endl;
			else if(a>=10&&ans>=10)cout<<i<<"/"<<a<<"/"<<ans<<endl;
			*/
			printf("%d/%02d/%02d\n",i,a,ans);
		}
		else cout<<"none"<<endl;
	}
	return 0;
}
