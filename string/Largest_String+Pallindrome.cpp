#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int i, j;

//WAP to input N strings, print the largest string, its length and check whether its a pallindrome or not

int Check_Pal(char s[])
{
	int p=1;
	i=0;
	j=strlen(s)-1;

	while(i<j && p)
		if(s[i++]!=s[j--])
			p--;

	return p;
}


char* Get_Str(int n)
{
	char *cur_str = new char[20], *max_str = new char [20];
	int cur_len, max_len=0;
	cin.get();

	for(i=1; i<=n; i++)
	{
		cout<<endl<<"Input string #"<<i<<"..."<<endl;
		gets(cur_str);
		cur_len=strlen(cur_str);

		if(cur_len>max_len)
		{
			max_len=cur_len;
			strcpy(max_str, cur_str);
			max_str[max_len]='\0';
		}
	}

	delete[] cur_str, max_str;
	return max_str;
}


int main()
{
	int N;
	char *str = new char[20];

	cout<<"How many strings do you want to enter?"<<endl;
	cin>>N;
	strcpy(str, Get_Str(N));

	cout<<endl<<"The longest string("<<strlen(str)<<" characters) is..."<<endl;
	puts(str);

	if(Check_Pal(str))
		cout<<"Yes, Given string IS A PALLINDROME";
	else
		cout<<"Given string IS NOT A PALLINDROME";

	delete[] str;	
}