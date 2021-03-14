#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//https://www.spoj.com/problems/PESADA04/
//Use only Test case because language C is allowed
//Minimum Cost Hamiltonian Cycle
// O((n-1)!) time (without dp) and O(n^2) space


int TSP(int n, vector< vector<int> > dist, vector< vector<int> > dp, int pos=0, int mask=1)
{
	if(mask==(1<<n)-1)
		return dist[pos][0];

	if(dp[mask][pos]!=-1)
		return dp[mask][pos];

	int ans=INT_MAX;
	for(int city=0; city<n; city++)
		if((mask&(1<<city))==0)
			ans=min(ans, dist[pos][city] + TSP(n, dist, dp, city, mask|(1<<city) ) );

	return dp[mask][pos]=ans;
}


void solve()
{
	int n;
	cin>>n;
	n++;

	vector< vector<int> > dist(n, vector<int> (n,0));
	vector< vector<int> > dp(1<<n, vector<int> (n,-1));

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i!=j)
				cin>>dist[i][j];

	cout<<TSP(n, dist, dp)<<endl;
}


int main()
{
	int t;
	cin>>t;

	while(t--)
		solve();

	return 0;
}