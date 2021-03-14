#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//WAP 2 get details of the 3 oldest persons standing in an ATM queue

class person
{
	public:
	string name;
	int age;
};

template<class T>
class compare
{
	public:

	bool operator()(T a, T b)
	{
		return b.age>a.age;
	}
};


int main()
{
	priority_queue< person, vector<person>, compare<person> > pq;
	int n=5, k=3, num;
	string str;
	person p;
	cin>>n>>k;

	while(n--)
	{
		cin>>p.name>>p.age;
		pq.push(p);
	}

	while(k--)
	{
		p=pq.top();
		cout<<p.name<<" "<<p.age<<endl;
		pq.pop();
	}

	return 0;
}