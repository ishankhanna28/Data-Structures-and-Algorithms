#include <iostream>
using namespace std;


int TILE(int n, int m)
{
	if(n<m)
		return 1;

	else 
		return TILE(n-1, m) + TILE(n-m, m);
}


void solve()
{
	int N, M;
	cin>>N>>M;
	cout<<TILE(N,M)<<endl;
}


int main()
{
	int T=1;
	cin>>T;

	while(T--)
		solve();

	return 0;
}