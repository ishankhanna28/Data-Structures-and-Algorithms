#include<iostream>
using namespace std;


bool Can_Win_Schol(int n1, int m1, int x1, int y1, int mid1)
{
	if( m1 + (n1-mid1)*y1 >= mid1*x1)
		return true;

	else
		return false;
}


int CB_Schol(int n, int m, int x, int y)
{
	int lb=0, ub=n, mid, ans;

	while(lb<=ub)
	{
		mid=(lb+ub)/2;

		if(Can_Win_Schol(n,m,x,y,mid))
		{
			ans=mid;
			lb=mid+1;
		}

		else
		{
			ub=mid-1;
		}
	}

	return ans;
}


int main()
{
	int N, M, X, Y;
	cin>>N>>M>>X>>Y;
	cout<<CB_Schol(N,M,X,Y)<<endl;
	return 0;
}