#include <iostream>
#include <deque>
using namespace std;
//https://www.spoj.com/problems/ARRAYSUB/

int main()
{
	int n, k, i;
	cin>>n;
	const int K=n;
	int a[K];

	for(i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	deque<int> d(k);

	for(i=0; i<k; i++)
	{
		while(!d.empty() && a[i]>a[d.back()])
			d.pop_back();

		d.push_back(i);
	}

	cout<<a[d.front()]<<" ";

	for(; i<n; i++)
	{
		while(!d.empty() && d.front()<=i-k)
			d.pop_front();

		while(!d.empty() && a[i]>a[d.back()])
			d.pop_back();

		d.push_back(i);
		cout<<a[d.front()]<<" ";
	}

	cout<<endl;
	return 0;
}

