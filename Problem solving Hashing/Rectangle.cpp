#include <iostream>
#include <set>
using namespace std;

//WAP to count the no. of rectangles that can be drawn between N points in 2D
//given all sides of rectangle are parallel to either axes

#define point pair<int,int>
#define x first
#define y second

//for custom class, cannot use map and have to give comparator class in set(BST)

int RectCount(set<point> s)		//O(N^2xlogN)
{
	int cnt=0;

	for(auto it=s.begin(); it!=prev(s.end()); it++)
	{
		for(auto jt=next(it); jt!=s.end(); jt++)
		{
			point p1=*it, p2=*jt;

			if(p1.x==p2.x or p1.y==p2.y)
				continue;

			point p3=make_pair(p1.x, p2.y);
			point p4=make_pair(p2.x, p1.y);

			if(s.find(p3)!=s.end() and s.find(p4)!=s.end())
				cnt++;
		}
	}

	return cnt/2;
}


int main()
{
	set<point> s;
	int k, X, Y;
	cin>>k;

	while(k--)
	{
		cin>>X>>Y;
		s.insert(make_pair(X,Y));
	}

	cout<<RectCount(s)<<endl;
	return 0;
}


/*
INPUT
8
0 0
0 1
1 1
1 0
2 1
2 0
3 1
3 0

OUTPUT
6
*/