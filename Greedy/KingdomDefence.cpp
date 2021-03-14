#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://www.spoj.com/problems/DEFKIN/

void solve()
{
	int X, Y, w, h, n;
	cin>>w>>h>>n;

	vector<int> x, y;
	x.reserve(n);
	y.reserve(n);

	for(int i=0; i<n; i++)
	{
		cin>>X>>Y;
		x.push_back(X);
		y.push_back(Y);
	}

	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	int dx = x[0]-1;
	int dy = y[0]-1;

	for(int i=1; i<n; i++)
	{
		dx = max(dx, x[i]-x[i-1]-1);
		dy = max(dy, y[i]-y[i-1]-1);
	}

	dx = max(dx, w-x[n-1]);
	dy = max(dy, h-y[n-1]);
	cout<<dx*dy<<endl;

	x.clear();
	y.clear();
}


int main()
{
	int T;
	cin>>T;

	while(T--)
		solve();

	return 0;
}