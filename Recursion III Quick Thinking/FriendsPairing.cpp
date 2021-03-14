//WAP to find the no. of ways N friends can go to a party on bikes if they can travel either alone or in pairs.

#include <iostream>
using namespace std;


int f(int n)
{
	if(n==1 || n==0)
		return 1;

	else 
		return f(n-1) + (n-1)*f(n-2);

}						       

int main()
{
	int N=3;
//	cin>>N;
	cout<<f(N)<<endl;
	return 0;
}