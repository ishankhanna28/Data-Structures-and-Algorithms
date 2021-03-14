#include <iostream>
#include <climits>
using namespace std;

//WAP 2 get the min no. of steps to reduce a number to 1 in linear time & space


int MinSteps(int n, int dp[])
{
	for(int i=2; i<=n; i++)
	{
		int a, b, c;
		a=b=c=INT_MAX;

		if(i%3==0)
			a=dp[i/3];

		if(i%2==0)
			b=dp[i/2];

		c=dp[i-1];
		dp[i]=min(a,min(b,c))+1;
	}

	return dp[n];
}


int MinStepBU(int n)
{
	const int K=n+1;
	int dp[K]={0};
	return MinSteps(n,dp);
}


int main()
{
	int n;
//	cin>>n;
	n=10;

	cout<<MinStepBU(n)<<endl;
	return 0;	
}