#include <iostream>
#include <set>
using namespace std;
#define psi pair<string,int>

//Comparator Class
class cmp
{
	public:
	bool operator()(psi a, psi b)
	{
		return a.second>b.second;
	}
};


int main()
{
	psi p1 = make_pair("B",100);
	psi p2 = make_pair("A",40);
	psi p3 = make_pair("C",120);
	psi p4 = make_pair("D",10);

	multiset<psi,cmp> m;
	m.insert(p1);
	m.insert(p2);
	m.insert(p3);
	m.insert(p4);

	for(auto p:m)
		cout<<p.first<<" "<<p.second<<endl;
	return 0;

}