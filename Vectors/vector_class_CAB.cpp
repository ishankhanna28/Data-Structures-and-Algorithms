#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class CAB
{
	public:
		string name;
		int x,y;

	CAB(string name, int x, int y)
	{
		this->name = name;
		this->x = x;
		this->y= y;
	}

	int dist()
	{
		return x*x + y*y;
	}
};


bool compare(CAB a, CAB b)
{
	if(a.dist() == b.dist())
		return b.name > a.name;

	else 
		return b.dist() > a.dist();
}


int main()
{
	int n, i, x, y;
	vector<CAB> v;
	cin>>n;
	v.reserve(n);
	string name;

	for(i=0; i<n; i++)
	{
		cin>>name>>x>>y;
		CAB C(name,x,y);
		v.push_back(C);
	}

	sort(v.begin(), v.end(), compare);

	for(auto c:v)
		cout<<c.name<<" at location coordinates ("<<c.x<<","<<c.y<<")"<<endl;

	return 0;
}