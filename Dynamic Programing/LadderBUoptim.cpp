#include <iostream>
using namespace std;

//We can further optimize calculation of dp[n] using sliding window method as shown below

int Ladder(int n, int k)		//O(n) time & O(n) space
{
	const int K1=n+1;
	int dp[K1]={0};
	dp[0]=dp[1]=1;

	for(int i=2; i<=n; i++)
	{
		dp[i]=2*dp[i-1];

		int temp=i-k-1;
		if(temp>=0)
			dp[i]-=dp[temp];
	}

	return dp[n];
}

int main()
{
	int n=6, k=3;
	cout<<Ladder(n,k)<<endl;
	return 0;
}