#include<bits/stdc++.h>
using namespace std;
int ck[30],N,cnt,mt[30];
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length();)
	{
		if(s[i+1]==':')
		{
			ck[s[i]-'a']=2;
			i+=2;
		}
		else 
		{
			ck[s[i]-'a']=1;
			i++;
		}
	}
	cin>>N;
	getchar();
	while(N--)
	{
		cnt++;
		char p[500];
		gets(p);
		string s(p);
		memset(mt,0,sizeof(mt));
		string v[30];
		//cout<<s<<endl;
		int k=s.find(' ',0);
		if(k==string::npos)
		{
			//printf("1111");
			cout<<"Case "<<cnt<<':'<<endl;
			continue;
		}
		for(int i=k;i<s.length();)
		{
			if(s[i+1]=='-'&&s[i+3]==' '&&ck[s[i+2]-'a']||(s[i+1]=='-'&&ck[s[i+2]-'a']&&i+3==s.length()))
			{
				if(ck[s[i+2]-'a']==1)
				{
					mt[s[i+2]-'a']=1;
					i=i+3;
				}
				else
				{
					if(i+4>=s.length())break;
					mt[s[i+2]-'a']=1;
					int tp=s.find(" ",i+4);
					if(tp==string::npos)
					{
						string s1=s.substr(i+4,s.length()-i-4);
						v[s[i+2]-'a']=s1;
						break;
					}	
					else 
					{
						string s1=s.substr(i+4,tp-i-3);
						v[s[i+2]-'a']=s1;
						i=tp;		
					}
				}
			}
			else break;
		}
		cout<<"Case "<<cnt<<':';
		for(int i=0;i<=26;i++)
		{
			if(mt[i]&&ck[i]==1)
				printf(" -%c",i+'a');
			else if(mt[i]&&ck[i]==2)
			{
				printf(" -%c ",i+'a');
				cout<<v[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
