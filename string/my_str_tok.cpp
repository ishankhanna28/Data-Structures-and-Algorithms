#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;


char *MY_STR_TOK(char *s, char delim)
{
	static int i=0;
	static char *given_str = new char[80];

	if(s!=NULL)
		strcpy(given_str,s);

	if(given_str[i]=='\0')
		return NULL;

	int j=0;
	char *new_str = new char[strlen(given_str)+1];

	while(given_str[i]!='\0')
	{
		if(given_str[i]!=delim)
		{
			new_str[j++]=given_str[i++];
		}

		else
		{
			new_str[j]='\0';
			i++;
			return new_str;
		}
	}

	new_str[i]='\0';
	given_str=NULL;
	return new_str;
}


int main()
{	char ch, s2[80];
	cout<<"Input a string..."<<endl;
	gets(s2);
	cout<<"Enter delimiter character..."<<endl;
	ch=cin.get();

	char *p=MY_STR_TOK(s2,ch);
	cout<<p<<endl;

	while(p!=NULL)
	{
		p=MY_STR_TOK(NULL,ch);
		cout<<p<<endl;
	}
	return 0;
}