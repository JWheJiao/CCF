#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string s2[101];		//�ַ��������������ÿ��������ַ��� 
int w=0;
//�����Դ�Сд			
void notignore(string s1,string s) 
{
	//��s1�в����Ӵ�s�����ҵ������s2�� 
	if(s1.find(s)!=-1)
	{
		s2[w]=s1;
		w++;
	}				
}
//���ַ���ת��ΪСд 
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
//���Դ�Сд 
void ignore(string s1,string s)
{
	int j;
	//�Ƚ����ַ���ȫתΪСд 
	string ss1 = convert(s);
	string ss2 = convert(s1);
	//�����Ӵ� 
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
	//ѭ������ 
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
	//���s2�ַ��� 
	int j=0;
	while(s2[j].length())
	{
		cout<<s2[j]<<endl;
		j++;
	}
}
