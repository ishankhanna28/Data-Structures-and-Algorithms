#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void solve()
{
	int d, n;
	float med=0.0;
	cin>>n;
	priority_queue<int> lh;									//max heap
	priority_queue< int, vector<int>, greater<int> > rh;	//min heap

	while(n--)
	{
		cin>>d;

		if(lh.size()>rh.size())
		{
			if(d>med)
			{
				rh.push(d);
				med = (lh.top()+rh.top())/2.0;
			}

			else
			{
				rh.push(lh.top());
				lh.pop();
				lh.push(d);
				med=(lh.top()+rh.top())/2.0;
			}
		}


		else if(rh.size()>lh.size())
		{
			if(d>med)
			{
				lh.push(rh.top());
				rh.pop();
				rh.push(d);
				med=(lh.top()+rh.top())/2.0;
			}

			else
			{
				lh.push(d);
				med=(lh.top()+rh.top())/2.0;
			}
		}


		else
		{
			if(d>med)
			{
				rh.push(d);
				med=rh.top();
			}

			else
			{
				lh.push(d);
				med=lh.top();
			}
		}

		cout<<med<<" ";
	}
	cout<<endl;
}


int main()
{
	int T=1;
	cin>>T;

	while(T--)
		solve();

	return 0;
}