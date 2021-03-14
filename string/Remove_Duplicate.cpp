#include<iostream>
#include<stdio.h>
using namespace  std;
//WAP to remove consecutive duplicate characters from a string.

void Remove_Duplicate(char s[])
{	
	int i=0, j=1;
	
	for(j=1; s[j]!='\0'; j++)
		if(s[i]!=s[j])
			s[++i]=s[j];

	s[++i]='\0';
	cout<<endl<<"All consecutive duplicate characters have been removed from the given  string."<<endl;
}


int main()
{
	char *str = new char[20];

	cout<<"Input a string..."<<endl;
	gets(str);

	Remove_Duplicate(str);

	cout<<endl<<"The modified string is ..."<<endl;
	puts(str);

	delete[] str;
}