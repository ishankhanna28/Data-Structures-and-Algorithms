#include <iostream>
#include <cstring>
#include <string>
using namespace std;


void SubRec(char is[], char os[], int i=0, int j=0)
{
	if(is[i]=='\0')
	{
    	os[j]='\0';
		cout<<os<<" ";
        return;
	}

	SubRec(is, os, i+1, j);

	os[j] = is[i];
	SubRec(is, os, i+1, j+1);
}


int main()
{
	char istr[80];
	cin>>istr;
    const int K1=strlen(istr);
    char ostr[K1];

	SubRec(istr, ostr);
	int l=1<<K1;
	cout<<endl<<l<<endl;
	return 0;
}