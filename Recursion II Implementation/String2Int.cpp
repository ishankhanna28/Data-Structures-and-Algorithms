#include <iostream>
#include <stdio.h>
#include<string.h>
using namespace std;

int String2Int(char s[], int n, int t=1)
{
	if(n<0)
		return 0;

	int num = s[n]-48;
	return num*t + String2Int(s, n-1, t*10);
}


int main()
{
	char str[10];
	gets(str);

	cout<<String2Int(str, strlen(str)-1)<<endl;
	return 0;
}