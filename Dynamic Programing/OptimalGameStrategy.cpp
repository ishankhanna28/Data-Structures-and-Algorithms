#include <iostream>
#include <vector>
using namespace std;


int MaxGame(int a[], int i, int j, vector<vector<int>> &dp)		//O(N) time & O(n^2) space
{
	if(i>j)
		return 0;

	if(dp[i][j]>0)
		return dp[i][j];

	int x = MaxGame(a, i+1, j-1, dp);

	return dp[i][j]=max(a[i] + min(x,MaxGame(a,i+2,j,dp)), a[j] + min(x,MaxGame(a,i,j-2,dp)));
}


int main()
{
	int n;
	cin>>n;

	const int k=n;
	int a[k];

	for(int i=0; i<n; i++)
		cin>>a[i];

	vector<vector<int>> dp(n, vector<int> (n,0));

	cout<<MaxGame(a,0,n-1,dp)<<endl;
	return 0;
}