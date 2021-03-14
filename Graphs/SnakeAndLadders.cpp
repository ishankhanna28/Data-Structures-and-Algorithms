#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;


class Graph
{
	unordered_map<int, list<int> > m;
	public:

	void addEdge(int x, int y)
	{
		m[x].push_back(y);
	}


	int bfs(int src, int dest)
	{
		queue<int> q;
		unordered_map<int,int> dist;
		unordered_map<int,int> parent;

		for(auto p:m)
			dist[p.first]=-1;

		q.push(src);
		dist[src]++;

		while(!q.empty())
		{
			int tmp = q.front();

			for(auto nbr:m[tmp])
			{
				if(dist[nbr]==-1)
				{
					q.push(nbr);
					dist[nbr]=dist[tmp]+1;
					parent[nbr]=tmp;
				}
			}

			q.pop();
		}


		//To print the path
/*		int n=dist[dest];
		const int K2=n+1;
		int a[K2];
		a[0]=src;

		for(int tmp=dest; tmp!=src; tmp=parent[tmp])
			a[n--]=tmp;

		for(int i=0; i<K2; i++)
			cout<<a[i]<<" -> ";

		cout<<"WINNER"<<endl;*/
		return dist[dest];
	}
};


void solve()
{
	int n, l, s, x, y;
	cin>>n>>l>>s;
	const int K1=n+1;
	int board[K1]={0};

	while(l--)
	{
		cin>>x>>y;
		board[x]=y-x;
	}

	while(s--)
	{
		cin>>x>>y;
		board[x]=y-x;
	}

	Graph g;
	g.addEdge(n,n);

	for(int i=1; i<n; i++)
	{
		for(int j=1; j<=6; j++)
		{
			int tmp = i+j;
			tmp+= board[tmp];

			if(tmp<=n)
				g.addEdge(i, tmp);
		}
	}

	cout<<g.bfs(1,n);
}


int main()
{
	int t;
	cin>>t;

	while(t--)
		solve();

	return 0;
}
