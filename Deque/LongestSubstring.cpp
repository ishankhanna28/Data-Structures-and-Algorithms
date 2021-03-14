#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

//WAP 2 Find the length of the longest substring without a repeating character.
//We implement Sliding Window Concept using 2 Pointer Method to solve in Linear Complexity.

int main()
{
	char s[80];
	gets(s);
	int n=strlen(s), max_len=1, map[256], i=0, j=0;

	for(; j<256; j++)
		map[j]=-1;


	for(j=0; j<n; j++)
	{
		if(map[s[j]]>=i)
			i=map[s[j]]+1;

		max_len=max(max_len, j-i+1);
		map[s[j]]=j;
	}

	cout<<max_len<<endl;
	return 0;
}