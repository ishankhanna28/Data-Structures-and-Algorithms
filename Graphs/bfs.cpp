#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


template<typename t>
class Graph
{
	unordered_map<t,list<t>> m;
	public:

	void addEdge(t x, t y)
	{
		m[x].push_back(y);
		m[y].push_back(x);
	}


	void bfs(t src)
	{
		int cnt;
		queue<t> q;
		unordered_set<t> s;

		q.push(src);
		s.insert(src);

		while(!q.empty())
		{
			t tmp = q.front();

			for(auto nbr:m[tmp])
			{
				if(s.find(nbr)==s.end())
				{
					q.push(nbr);
					s.insert(nbr);
				}
			}

			cout<<tmp<<" ";
			q.pop();
		}
	}
};


int main()
{
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.bfs(0);
	cout<<endl;
	return 0;
}