#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//O(n^2) space and O(n^3) time
//https://www.spoj.com/problems/MIXTURES/

int Sum(int a[], int i, int j)
{
	int sum=0;

	for(int k=i; k<=j; k++)
		sum+=a[k];

	return sum%100;
}


int MinSmoke(int a[], int i, int j, vector<vector<int>> &dp)
{
	if(i>=j)
		return 0;

	if(dp[i][j]!=INT_MAX)
		return dp[i][j];

	for(int k=i; k<j; k++)
	dp[i][j]=min(dp[i][j],MinSmoke(a,i,k,dp)+MinSmoke(a,k+1,j,dp)+(Sum(a,i,k)*Sum(a,k+1,j)));

	return dp[i][j];
}


void solve(int n)
{
	const int k=n+1;
	int a[k];

	for(int i=1; i<=n; i++)
		cin>>a[i];

	vector<vector<int>> dp(n+1, vector<int> (n+1,INT_MAX));
	cout<<MinSmoke(a,1,n,dp)<<endl;
}


int main()
{
	int n;
	while(cin>>n)
		solve(n);
	return 0;
}