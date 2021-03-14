#include <iostream>
#include <climits>
using namespace std;

//WAP 2 get the min no. of steps to reduce a number to 1 in linear time & space


int MinSteps(int n, int dp[])
{
	if(n==1)
		return 0;

	if(dp[n]>0)
		return dp[n];


	int a, b, c;
	a=b=c=INT_MAX;

	if(n%3==0)
		a=MinSteps(n/3,dp);

	if(n%2==0)
		b=MinSteps(n/2,dp);

	c=MinSteps(n-1,dp);
	return dp[n]=min(a,min(b,c))+1;
}


int MinStepTD(int n)
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

	cout<<MinStepTD(n)<<endl;
	return 0;	
}