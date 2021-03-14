#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;


void ReplacePI(char str[], int i=0)
{
	if(str[i]=='\0')
		return;

	else if(str[i]=='p' && str[i+1]=='i')
	{
		for(int j=strlen(str); j>=i+2; j--)
			str[j+2]=str[j];

		str[i]='3';
		str[i+1]='.';
		str[i+2]='1';
		str[i+3]='4';

		ReplacePI(str, i+4);
	}

	else 
		ReplacePI(str, i+1);
}



void solve()
{
	char s[1000];
	gets(s);
	ReplacePI(s);

	if(strlen(s))
		puts(s);
}


int main()
{
	int T=1;
	cin>>T;
	T++;

	while(T--)
        solve();

	return 0;
}