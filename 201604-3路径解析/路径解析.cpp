#include<bits/stdc++.h>
using namespace std;
int p;
string cur;
int main()
{
	cin>>p;
	cin>>cur;
	getchar();
	while(p--)
	{
		char c,ch[1005];
		int i=0;
		while((c=getchar())!='\n')
			ch[i++]=c;
		ch[i]='\0';
		if(strlen(ch)==0)
		{
			cout<<cur<<endl;
			continue;
		}
		//printf("%s\n",ch);
		string tp(ch);
		if(tp[0]!='/')tp=cur+"/"+tp;
		int t=tp.find("/./");
		while(t!=string::npos)
		{
			tp=tp.substr(0,t)+tp.substr(t+2,tp.length()-t-2);
			t=tp.find("/./");
		}
		t=tp.find("//");
		while(t!=string::npos)
		{
			int k=t;
			while(tp[k]=='/')k++;
			tp=tp.substr(0,t+1)+tp.substr(k,tp.length()-k);
			t=tp.find("//");
		}
		t=tp.find("/../");
		while(t!=string::npos)
		{
			if(t==0)
			{
				tp=tp.substr(3,tp.length()-3);
				t=tp.find("/../");
				continue;
			}
			int k=t-1;
			while(tp[k]!='/')k--;
			tp=tp.substr(0,k+1)+tp.substr(t+4,tp.length()-t-4);
			t=tp.find("/../");
		}
		if(tp[tp.length()-1]=='/'&&tp.length()>1)tp=tp.substr(0,tp.length()-1);
		if(tp.length()>=2&&tp[tp.length()-1]=='.'&&tp[tp.length()-2]=='/')
		{
			if(tp.length()==2)tp="/";
			else
				tp=tp.substr(0,tp.length()-2);
		}
		if(tp.length()>=3&&tp[tp.length()-1]=='.'&&tp[tp.length()-2]=='.'&&tp[tp.length()-3]=='/')
		{
			if(tp.length()==3)tp="/";
			else
			{
				int k=tp.length()-4;
				while(tp[k]!='/')k--;
				tp=tp.substr(0,k);
			}
		}
		cout<<tp<<endl;
	}
	return 0;
}
