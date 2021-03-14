#include <iostream>
using namespace std;

int EXPO(int a, int n)	//O(N)
{
	if(!n)
		return 1;

	else 
		return a*EXPO(a,n-1);
}


int EXPONENT(int a, int n)	//O(logN)
{
	if(!n)
		return 1;

	int ans = EXPONENT(a, n/2);
//	int ans = EXPONENT(a, n/2) * EXPONENT(a, n/2);	is Ineffiecient since you 2 separate branches in recursion tree.
	ans*=ans;

	if(n%2)
		ans*=a;

	return ans;
}


int main()
{
	cout<<EXPONENT(3,5)<<endl;
	return 0;
}