#include <iostream>
#include <list>
using namespace std;

//Graph can be implemented as an array of lists.

int main()
{
	int v, e, x, y, wt;
	cin>>v>>e;
	const int k1=v;
	list<pair<int,int>> l[k1];

	/*
	list<pair<int,int>> *l;
	l = new list<pair<int,int>> [v];
	*/

	for(int i=1; i<=e; i++)
	{
		cin>>x>>y>>wt;
		l[x].push_back(make_pair(y,wt));
		l[y].push_back(make_pair(x,wt));
	}


	for(int i=0; i<v; i++)
	{
		cout<<"Linked List "<<i<<" : ";

		for(auto x:l[i])
			cout<<"("<<x.first<<","<<x.second<<") -> ";

		cout<<endl;
	}

	return 0;
}

/*
INPUT:
3 3
0 1 4
0 2 3
1 2 5

OUTPUT:
Linked List 0 : (1,4) -> (2,3) -> 
Linked List 1 : (0,4) -> (2,5) -> 
Linked List 2 : (0,3) -> (1,5) ->
*/