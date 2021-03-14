#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//LIS - Longest Increasing Subsequence
//DP-1
//dp[i] represents length of LIS ending at subscript i


vector<int> Print(int a[], int n, int dp[])	//O(n)
{
	int maxv=0, maxi=0;
	for(int i=0; i<n; i++)
		if(dp[i]>=maxv)
		{
			maxv=dp[i];
			maxi=i;
		}

	vector<int> v;
	v.reserve(maxv);
	maxv++;

	for(int i=maxi; i>=0; i--)
		if(dp[i]==maxv-1)
		{
			v.push_back(a[i]);
			maxv--;
		}

	reverse(v.begin(),v.end());
	return v;
}


int LIS(int a[], int n, int dp[])		//O(n^2) time & O(n) space
{
	if(dp[n]>0)
		return dp[n];

	int maxv=0, temp;

	for(int i=n-1; i>=0; i--)
		if(a[i]<a[n])
			maxv=max(maxv,LIS(a,i,dp));
		else
			temp=LIS(a,i,dp);

	return dp[n]=maxv+1;
}


vector<int> LisTD(int a[], int n)	//O(1)
{
	const int k=n;
	int dp[k]={0};
	int ans = LIS(a,n-1,dp);
	return Print(a,n,dp);
}


vector<int> LisBU(int a[], int n)		//O(n^2) time & O(n) space
{
	const int k=n;
	int dp[k]={0};
	int mav=0;

	for(int i=0; i<n; i++)
	{
		int maxv=0;

		for(int j=0; j<i; j++)
			if(a[j]<a[i])
				maxv=max(maxv,dp[j]);

		dp[i]=maxv+1;
	}

	return Print(a,n,dp);
}


int main()
{
	int a[] = {1, 5, 2, 3, 4, 9, 6, 10, 1};
	int n =sizeof(a)/sizeof(int);
	vector<int> v = LisBU(a,n);

	for(auto x:v)
		cout<<x<<" ";

	cout<<endl<<v.size()<<endl;
	return 0;
}


