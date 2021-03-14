#include <iostream>
#include <stack>
#include <climits>
using namespace std;


int main()
{
	stack<pair<int,int>> s;
	s.push(make_pair(-1, INT_MAX));
	int n, x;
	cin>>n;

	for(int idx=0; idx<n; idx++)
	{
		cin>>x;

		while(x > s.top().second)
			s.pop();

		cout<<(idx - s.top().first)<<" ";
		s.push(make_pair(idx, x));
	}

	cout<<"END"<<endl;
	return 0;
}