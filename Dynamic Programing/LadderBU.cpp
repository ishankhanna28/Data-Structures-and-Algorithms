#include <iostream>
using namespace std;


int LadderBU(int n, int k)		//O(n*k) time & O(n) space
{
	const int K1=n+1;
	int dp[K1]={0};

	dp[0]=dp[1]=1;

	for(int i=2; i<=n; i++)
		for(int j=1; j<=k and i>=j; j++)
			dp[i]+=dp[i-j];

	return dp[n];
}


int main()
{
	int n=6, k=3;
	cout<<LadderBU(n,k)<<endl;
	return 0;
}