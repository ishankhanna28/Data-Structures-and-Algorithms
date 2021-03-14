#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };


void KEYPAD(char is[], char os[], int i=0, int j=0)
{	

	if(is[i]=='\0')
	{
		os[j]= '\0';
		puts(os);
		return;
	}

	int pos = is[i] - 48;

	for(int t=0; table[pos][t]!='\0'; t++)
	{
		os[j] = table[pos][t];
		KEYPAD(is, os, i+1, j+1);
	}
}


int main()
{
	char istr[11], ostr[11];
	gets(istr);
	KEYPAD(istr, ostr);
	return 0;
}