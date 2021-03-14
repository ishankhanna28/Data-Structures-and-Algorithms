#include <iostream>
#include <queue>
using namespace std;


int MinCost(int a[], int n)
{
	priority_queue< int, vector<int>, greater<int> > p(a,a+n);
	int cost=0, len;

	while(p.size()>1)
	{
		len=0;

		len+=p.top();
		p.pop();
		len+=p.top();
		p.pop();

		cost+=len;
		p.push(len);
	}

	return cost;
}


int main()
{
	int ropes[]={4, 3, 2, 6};
	int N = sizeof(ropes)/sizeof(int);

	cout<<MinCost(ropes,N)<<endl;
	return 0;
}