#include <iostream>
#include <vector>
#include <climits>
using namespace std;


//DP-2
//dp[i] represents last element(not subscript) of LIS having length i
//Bottom up build in O(n^2) time & O(n) space


vector<int> LIS(int a[], int n)
{
	vector<int> dp(n+1,INT_MAX);
	dp[0]=INT_MIN;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(dp[j]<a[i] and a[i]<dp[j+1])
				dp[j+1]=a[i];

	int i;
	for(i=0; i<=n; i++)
		if(dp[i]==INT_MAX)
			break;

	cout<<--i<<endl;	//Size of LIS
	vector<int> v;
	v.reserve(i);

	for(int i=1; i<=n and dp[i]!=INT_MAX; i++)
		v.push_back(dp[i]);

	return v;
}


int main()
{
	int a[] = {1, 5, 2, 3, 4, 9, 6, 10, 1};
	int n =sizeof(a)/sizeof(int);
	vector<int> v = LIS(a,n);

	for(auto x:v)
		cout<<x<<" ";

	cout<<endl;
	return 0;
}