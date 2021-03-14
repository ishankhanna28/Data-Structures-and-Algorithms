#include <iostream>
using namespace std;


int MaxSub(int a[], int n)		//Bottom Down O(N) time and space
{
	const int k=n;
	int dp[k]={0};

	dp[0]=max(a[0],0);
	int maxv=dp[0];

	for(int i=1; i<n; i++)
	{
		dp[i]= max(dp[i-1]+a[i], 0);
		maxv=max(maxv,dp[i]);
	}

	if(maxv==0 and a[0]!=0)
	{
		maxv=a[0];

		for(int i=1; i<n; i++)
			maxv=max(maxv,a[i]);
	}

	return maxv;
}


int main()
{
\	int a[]={-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
//	int a[]={-2, -4, -7};
	int n = sizeof(a)/sizeof(int);
	cout<<MaxSub(a,n)<<endl;
	return 0;
}