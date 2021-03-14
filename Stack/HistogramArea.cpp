#include <iostream>
#include <stack>
using namespace std;
#define int long long
//O(N)


int32_t main()
{
	stack<pair<int,int>> s;
	int i, n, num, l, b, ub, lb, ar, max_ar=-1;
	cin>>n;
	s.push(make_pair(-1,-1));


	for(i=0; i<=n ; i++)
	{
		if(i==n)
			num = -2;

		else
			cin>>num;

		while(num < s.top().second)
		{
			l = s.top().second;
			s.pop();

			if(s.empty())
				break;

			lb = s.top().first;
			ub = i;
			b = (ub-lb-1);

			ar = l*b;
			max_ar = max(max_ar, ar);
		}

		if(s.empty())
			break;

		s.push(make_pair(i, num));
	}

	cout<<max_ar<<endl;
	return 0;
}