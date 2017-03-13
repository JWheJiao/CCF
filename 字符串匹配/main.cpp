#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string s2[101];		//字符串数组用来存放每次输出的字符串 
int w=0;
//不忽略大小写			
void notignore(string s1,string s) 
{
	//在s1中查找子串s，若找到则存入s2中 
	if(s1.find(s)!=-1)
	{
		s2[w]=s1;
		w++;
	}				
}
//将字符串转换为小写 
string convert(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			s[i] += 32;
		}
	}
	return s;
}
//忽略大小写 
void ignore(string s1,string s)
{
	int j;
	//先将两字符串全转为小写 
	string ss1 = convert(s);
	string ss2 = convert(s1);
	//查找子串 
	if(ss2.find(ss1)!=-1)
	{
		s2[w]=s1;
		w++;	
	}						
}

int main()
{
	string s,s1;
	cin>>s;
	int t,n;
	cin>>t;
	cin>>n;
	//循环输入 
	for(int i=0;i<n;i++)
	{
		cin>>s1;
		if(t==1)
		{
			notignore(s1,s);
		}
		if(t==0)
		{
			ignore(s1,s);
		}
		
	}
	//输出s2字符串 
	int j=0;
	while(s2[j].length())
	{
		cout<<s2[j]<<endl;
		j++;
	}
}
