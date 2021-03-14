#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator ITR;
int main()
{
	int a[]={10, 20, 30, 20, 10, 10};
	int n = sizeof(a)/sizeof(int);

	multiset<int> m(a, a+n);

	m.erase(20);	//delete all occurences of argument
	m.insert(15);

	cout<<m.count(10)<<endl;
	m.insert(15);
	m.insert(15);
	m.insert(40);
	m.insert(30);

	auto itr=m.find(15);	//location of first occurence
	cout<<(*itr)<<endl;

	pair<ITR,ITR> p = m.equal_range(15);
	for(auto it=p.first; it!=p.second; it++)
		cout<<*it<<" ";
	cout<<endl;

	//Print in range 15 to 30
	for(auto it=m.lower_bound(15); it!=m.upper_bound(30); it++)
		cout<<*it<<" ";
	cout<<endl;

	for(auto x:m)
		cout<<x<<" ";

	cout<<endl;
	return 0;
}