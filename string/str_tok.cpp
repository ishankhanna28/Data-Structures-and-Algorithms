#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>	//for strtok()
using namespace std;


int main()
{	char s1[80], str[10];
	cout<<"Input a string..."<<endl;
	gets(s1);
	cout<<"Enter delimiter string..."<<endl;
	gets(str);

	char *ptr=strtok(s1,str);
		cout<<ptr<<endl;

	while(ptr!=NULL)
	{
		ptr=strtok(NULL,str);
		cout<<ptr<<endl;
	}
	return 0;
}
