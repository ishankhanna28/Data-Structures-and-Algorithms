#include <iostream>
using namespace std;


int CatTD(int n, int dp[])						//O(n^2) time & O(n) space
{
	if(!n)
		return 1;

	if(dp[n]>0)
		return dp[n];

	for(int i=1; i<=n; i++)
		dp[n]+=CatTD(i-1,dp)*CatTD(n-i,dp);

	return dp[n];
}


int CatBU(int n)					//O(n^2) time & O(n) space
{
	const int k=n+1;
	int dp[k]={0};
	dp[0]++;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			dp[i]+=dp[j-1]*dp[i-j];

	return dp[n];
}


int main()
{
	int n=10;
	const int k=n+1;
	int dp[k]={0};

	cout<<CatTD(n,dp)<<endl;
	cout<<CatBU(n)<<endl;
	return 0;
}