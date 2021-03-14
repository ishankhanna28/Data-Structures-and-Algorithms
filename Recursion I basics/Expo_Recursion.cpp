#include <iostream>
using namespace std;

int EXPO(int a, int n)
{
	if(!n)
		return 1;

	else 
		return a*EXPO(a,n-1);
}


int main()
{
	cout<<EXPO(2,5)<<endl;
	return 0;
}