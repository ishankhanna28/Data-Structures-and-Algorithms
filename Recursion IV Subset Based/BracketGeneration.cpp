//WAP to print all possible strings of ballanced brackets using N pairs of round brackets.

#include <iostream>
#include <stdio.h>
using namespace std;


void BRACK(int n, char s[], int i=0, int opn=0, int cls=0)
{
	if(i==2*n)
	{
		s[i]='\0';
		puts(s);
	}

	if(opn<n)
	{
		s[i]='(';
		BRACK(n, s, i+1, opn+1, cls);
	}

	if(cls<opn)
	{
		s[i]=')';
		BRACK(n, s, i+1, opn, cls+1);
	}
}








int main()
{
	int N=3;
//	cin>>N;

	const int K1= 2*N + 1;
	char str[K1];

	BRACK(N, str);
	return 0;
}

