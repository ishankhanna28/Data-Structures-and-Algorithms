#include <iostream>
using namespace std;

int FAC(int n)
{
	return (n)? n*FAC(n-1) :1;
}

int main()
{
	int N = 5;	
	cout<<FAC(N)<<endl;
	return 0;
}