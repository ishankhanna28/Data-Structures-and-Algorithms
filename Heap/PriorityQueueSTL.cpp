#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int a[]={22, 44, 33, 11, 66, 55};
	int n = sizeof(a)/sizeof(int);

//	priority_queue<int> p;	By default creates a max heap
	priority_queue< int, vector<int>, greater<int> > p;	//Use inbuilt comparator greater<int> for Min Heap

	for(int i=0; i<n; i++)
		p.push(a[i]);

	while(!p.empty())
	{
		cout<<p.top()<<" ";
		p.pop();
	}

	cout<<endl;
	return 0;
}