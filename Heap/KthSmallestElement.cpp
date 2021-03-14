#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define val first
#define row second.first
#define col second.second
typedef pair< int, pair<int,int> > node;

//O(NlogK)

int Ksmall(vector< vector<int> > v, int k)
{
	int n=v.size(), min=0;
	const int N=n;
	int a[N][N]={0};

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			a[i][j]=0;

	priority_queue< node, vector<node>, greater<node> > p;
	p.push( make_pair(v[0][0], make_pair(0,0) ) );
	a[0][0]++;

	while(k--)
	{
		node cur = p.top();
		p.pop();
		min = cur.val;

		if(cur.col+1<n and a[cur.row][cur.col+1]==0)
		{
			p.push( make_pair(v[cur.row][cur.col+1], make_pair(cur.row,cur.col+1) ) );
			a[cur.row][cur.col+1]++;
		}
		
		if(cur.row+1<n and a[cur.row+1][cur.col]==0)
		{
			p.push( make_pair(v[cur.row+1][cur.col], make_pair(cur.row+1,cur.col) ) );
			a[cur.row+1][cur.col]++;
		}
	}

	return min;
}


int main()
{
	vector< vector<int> > v{ {10,20,30,40}, {15,25,35,45}, {29,29,37,48}, {32,33,39,50} };
	int k=7;

	cout<<Ksmall(v,k)<<endl;
	return 0;
}