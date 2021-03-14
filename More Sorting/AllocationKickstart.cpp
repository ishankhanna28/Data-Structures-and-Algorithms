//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56

#include <iostream>
#include <algorithm>
using namespace std;
#define int long long


void solve()
{
	static int cnt=1;
	int n, b, i=0;
	cin>>n>>b;

	const int K1=n;
	int a[K1];

	for(; i<n; i++)
		cin>>a[i];

	sort(a, a+n);

	i=0;
	for(; b>=0 && i<n; i++)
        b-=a[i];

	cout<<"Case #"<<cnt++<<": "<<i-1<<endl;
}


int32_t main()
{
	int T=1;
	cin>>T;

	while(T--)
		solve();

	return 0;
}