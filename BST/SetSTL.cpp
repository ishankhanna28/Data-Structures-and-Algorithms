#include <iostream>
#include <set>
using namespace std;

int main()
{
	int a[]={10, 20, 11, 9, 8, 11, 9, 10, 9, 9};
	int n=sizeof(a)/sizeof(int);
	set<int> s;

	for(int i=0; i<n; i++)
		s.insert(a[i]);

	s.erase(10);
	set<int>::iterator itr = s.find(11);
	s.erase(itr);
	s.insert(15);

	for(auto it=s.begin(); it!=s.end(); it++)
		cout<<*it<<" ";

	cout<<endl;
	return 0;
}