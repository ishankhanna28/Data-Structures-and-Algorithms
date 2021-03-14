//WAP to count number of binary strings of length N with no consecutive
#include <iostream>
using namespace std;


int f(int n)
{
	if(!n)
		return 1;

	else if(n==1)
		return 2;

	else 
		return f(n-1) + f(n-2);
}


int main()
{
	int N=3;
//	cin>>N;
	cout<<f(N)<<endl;
	return 0;
}