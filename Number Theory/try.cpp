#include <iostream>
#define ll long long
#define mod 1000005
using namespace std;


void solve()
{
	ll N, sum=0, i, count=0;
	cin>>N;

	ll n=N+1;
	ll A[mod]={0}, pre[mod]={0};

	for(i=1; i<n; i++)
	{
		cin>>A[i];
		sum+= A[i];

		sum=(sum+N)%N;
		pre[sum]++;
	}

	for(i=0; i<n; i++)
		if(pre[i])
		{
			ll m = pre[i];
			count+= (m*(m-1))/2;
		}

	cout<<count<<endl;
}


int main()
{
	ll T;
	cin>>T;

	while(T--)
		solve();

	return 0;
}