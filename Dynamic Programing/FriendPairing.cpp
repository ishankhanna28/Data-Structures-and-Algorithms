#include <iostream>
using namespace std;


int PairTD(int n, int dp[])						//O(N) time & space
{
	if(n==1 or n==0)
		return 1;

	if(dp[n]>0)
		return dp[n];

	return dp[n] = PairTD(n-1,dp) + (n-1)*PairTD(n-2,dp);
}


int PairBU(int n)
{
	const int k=n+1;
	int dp[k]={0};
	dp[0]=dp[1]=1;

	for(int i=2; i<=n; i++)
		dp[i]=dp[i-1]+(i-1)*dp[i-2];

	return dp[n];
}


int main()
{
	int n=4;
	const int k=n+1;
	int dp[k]={0};
	cout<<PairTD(n,dp)<<endl;
	cout<<PairBU(n)<<endl;
	return 0;
}