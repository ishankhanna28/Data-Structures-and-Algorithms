#include <iostream>
using namespace std;


int Ladder(int n, int k, int dp[])		//O(n*k) time & O(n) space
{
	if(n==0)
		return dp[0]=1;

	if(dp[n]>0)
		return dp[n];


	int sum=0, temp=min(n,k);

	for(int i=1; i<=n and i<=k; i++)
		sum+= Ladder(n-i, k, dp);

	return dp[n]=sum;
}



int LadderTD(int n, int k)
{
	const int K1=n+1;
	int dp[K1]={0};
	return Ladder(n,k,dp);
}


int main()
{
	int n=6, k=3;
	cout<<LadderTD(n,k)<<endl;
	return 0;
}