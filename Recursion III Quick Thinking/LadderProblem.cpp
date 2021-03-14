//There is a ladder with N steps. Person can climb 1, 2, 3 upto K steps at once.
//WAP to find number of ways in which he can climb the ladder

#include <iostream>
using namespace std;


int LADDER(int n, int k)
{
	if(n<0)
		return 0;

	else if(n==0)
		return 1;

	else 
	{
		int ans=0;

		for(int i=1; i<=k; i++)
			ans+= LADDER(n-i, k);

		return ans;
	}
}


int main()
{
	int N=4, K=3;
//	cin>>N>>K;
	cout<<LADDER(N,K)<<endl;
	return 0;
}