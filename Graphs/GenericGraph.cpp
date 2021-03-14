#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;


template<typename t>
class Graph
{
	unordered_map<t, list< pair<t,int> > > m;
	public:

	void addEdge(t x, t y, int l=-1, bool bidir=true)
	{
		m[x].push_back(make_pair(y,l));

		if(bidir)
			m[y].push_back(make_pair(x,l));
	}


	void Print()
	{
		for(auto p:m)
		{
			cout<<p.first<<" -> ";

			for(auto nbr:p.second)
				cout<<nbr.first<<","<<nbr.second<<" ";

			cout<<endl;

		}
	}
};


int main()
{
	Graph<char> g;
	g.addEdge('A','B',20,true);
	g.addEdge('B','D',30,true);
	g.addEdge('D','C',40,true);
	g.addEdge('C','A',10,true);
	g.addEdge('A','D',50,false);
	g.Print();
	return 0;
}