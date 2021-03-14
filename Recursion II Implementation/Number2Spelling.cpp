#include <iostream>
#include <stdio.h>
using namespace std;

void Num2Spel(int n)
{
	if(!n)
		return;

	char str[][10]={"zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};

	Num2Spel(n/10);
	cout<<str[n%10];
}


int main()
{
	Num2Spel(2048);
	cout<<endl;

	return 0;
}