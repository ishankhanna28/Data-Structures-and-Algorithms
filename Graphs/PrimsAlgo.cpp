#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>		//weight, destination

class Graph
{
	int v;
	vector<pii> *l;
	public:

	Graph(int v=3)
	{
		this->v=v;
		l=new vector<pii>[v];
	}

	void addEdge(int u, int v, int len)
	{
		l[u].push_back(make_pair(len,v));
		l[v].push_back(make_pair(len,u));
	}


	int MST()												//O(ElogE)
	{
		priority_queue< pii, vector<pii>, greater<pii> > q;	//min heap
		const int K=v;
		int visited[K]={0};

		int sum=0;
		q.push(make_pair(0,0));

		while(!q.empty())
		{
			auto node = q.top();				//log(e)
			q.pop();

			if(visited[node.second]>0)
				continue;

			visited[node.second]++;
			sum+=node.first;
		

			for(auto nbr:l[node.second])
				if(visited[nbr.second]==0)
					q.push(nbr);
		}

		return sum;
	}

	~Graph()
	{
		delete[] l;
	}
};


int main()
{
	int v, e;
	cin>>v>>e;
	Graph g(v);

	while(e--)
	{
		int x, y, z;
		cin>>x>>y>>z;
		g.addEdge(x,y,z);
	}

	cout<<g.MST()<<endl;
	return 0;
}