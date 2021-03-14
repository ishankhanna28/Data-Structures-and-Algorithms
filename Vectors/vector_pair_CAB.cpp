#include<iostream>
#include <utility>
#include<vector>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define xx first
#define yy second


bool compare(pii a, pii b)
{
	int da = a.xx*a.xx + a.yy*a.yy;
	int db = b.xx*b.xx + b.yy*b.yy;

	if(da==db)
		return b.xx>a.xx;

	else 
		return db>da;
}


int main()
{
	int n, i, x, y;
	vector<pii> v;
	cin>>n;
	v.reserve(n);

	for(i=0; i<n; i++)
	{
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}

	sort(v.begin(), v.end(), compare);

	for(auto c:v)
		cout<<"Car at location coordinates ("<<c.xx<<","<<c.yy<<")"<<endl;

	return 0;
}