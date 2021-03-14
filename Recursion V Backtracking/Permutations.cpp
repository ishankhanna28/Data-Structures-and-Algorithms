#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
#include <cstring>
using namespace std;


void PERMUTE(char s[], set<string> &S, int i=0)
{
	if(s[i]=='\0')
	{
		S.insert(s);
		return;
	}

	for(int j=i; s[j]!='\0'; j++)
	{
		swap(s[i], s[j]);
		PERMUTE(s, S, i+1);
		swap(s[i], s[j]);
	}
}


int main()
{
	char str[9];
	gets(str);
	set<string> S;

	PERMUTE(str, S);

	for(auto x:S)
		cout<<x<<endl;

	return 0;
}

