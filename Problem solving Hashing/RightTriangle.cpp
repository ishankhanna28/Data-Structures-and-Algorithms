#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//WAP 2 find the no. of rt. trgles can be made using N points in 2D
//given 2 sides of the triangle are parallel to X/Y axis 

#define point pair<int,int>
#define x first
#define y second


int main()
{
	vector<point> v;
	int k, X, Y, sum=0;
	cin>>k;
	unordered_map<int,int> fx, fy;

	while(k--)
	{
		cin>>X>>Y;
		v.push_back(make_pair(X,Y));

		if(fx.count(X))
			fx[X]++;
		else
			fx[X]=1;

		if(fy.count(Y))
			fy[Y]++;
		else
			fy[Y]=1;
	}


	for(auto p:v)
		sum+= (fx[p.x]-1)*(fy[p.y]-1);

	cout<<sum<<endl;
	return 0;
}