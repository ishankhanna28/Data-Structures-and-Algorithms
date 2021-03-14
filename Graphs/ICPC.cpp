#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <climits>
#include <string>
#include <map>
using namespace std;


template<typename T>
class Graph
{
	unordered_map<T, list< pair<int,T> > > m;
	map< pair<T,T>, int> fc;
	public:

	void addEdge(T x, T y, int len, int flight, bool bidir=true)
	{
		m[x].push_back(make_pair(len,y));
		fc[make_pair(x,y)]=flight;

		if(bidir)
		{
			m[y].push_back(make_pair(len,x));
			fc[make_pair(y,x)]=flight;
		}
	}


	unordered_map<T,int> Dijkstra(T src)
	{
		unordered_map<T,int> dist;
		set< pair<int,T> > s;

		for(auto node:m)
			dist[node.first]=INT_MAX;

		dist[src]=0;
		s.insert(make_pair(0,src));


		while(!s.empty())				//first->dist and second->node
		{
			auto itr = s.begin();
			auto node=*itr;
			s.erase(itr);

			for(auto nbr:m[node.second])
			{
				if(nbr.first + node.first < dist[nbr.second])
				{
					auto it = s.find(make_pair(dist[nbr.second],nbr.second));
					if(it!=s.end())
						s.erase(it);

					dist[nbr.second]=nbr.first + node.first;
					s.insert(make_pair(dist[nbr.second],nbr.second));
				}
			}
		}

		return dist;
	}


	int ICPC(T src, T dest)
	{
		auto dist1 = Dijkstra(src);
		auto dist2 = Dijkstra(dest);
		int ans = dist1[dest];

		for(auto X:m)
		{
			auto x = X.first;

			if(x==dest)
				continue;

			for(auto Y:X.second)
			{
				auto y=Y.second;

				if(y==src)
					continue;

				ans = min(ans, dist1[x] + fc[make_pair(x,y)] + dist2[y]);
			}
		}

		return ans;
	}
};


int main()
{
	Graph<string> india;
	india.addEdge("Amritsar", "Delhi", 3, 8);
	india.addEdge("Amritsar", "Jaipur", 5, 4);
	india.addEdge("Jaipur", "Delhi", 2, 6);
	india.addEdge("Jaipur", "Mumbai", 6, 5);
	india.addEdge("Mumbai", "Goa", 11, 6);
	india.addEdge("Mumbai", "Bhopal", 6, 3);
	india.addEdge("Mumbai", "Amravati", 8, 7);
	india.addEdge("Amravati", "Goa", 13, 12);
	india.addEdge("Amravati", "Bhopal", 1, 2);
	india.addEdge("Delhi", "Bhopal", 7, 14);
	cout<<india.ICPC("Delhi", "Amravati")<<endl;
	return 0;
}