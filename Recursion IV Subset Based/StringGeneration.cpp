#include <iostream>
#include <stdio.h>
using namespace std;


void StrGen(int n, int a[], char s[], int i=0, int j=0)
{
	int num =27;

	if(i==n)
	{
		s[j]= '\0';
		puts(s);
		return;
	}

	char ch= a[i] + 64;
//	cout<<"a[i]="<<a[i]<<endl;
	s[j]=ch;
	StrGen(n, a, s, i+1, j+1);

	if(i+1 < n)
		num = a[i+1] + (a[i]*10);

	if(num<=26)
	{
		char cha = num + 64;
		s[j]= cha;
		StrGen(n, a, s, i+2, j+1);
	}
}


int main()
{
	int A[]={1, 2, 3, 4};
	int N= sizeof(A)/sizeof(int);

	const int K1= N+1;
	char str[K1];
	StrGen(N, A, str);
	return 0;
}