#include<iostream>
#include<algorithm>
using namespace std;
int i;

bool can_keep_cows(int A[], int n, int c, int min)
{
	int last_cow = A[0], count=1;

	for(i=0; i<n ; i++)
	{
		if(A[i]-last_cow>=min)
		{
			last_cow=A[i];
			count++;

			if(count==c)
			return true;
		}
	}

	return false;
}


int agr_cow(int A[], int n, int c)
{
	sort(A,A+n);
	int lb=0, ub=A[n-1]-A[0], mid, ans=0;

	while(lb<=ub)
	{
		mid=(lb+ub)/2;

		if(can_keep_cows(A,n,c,mid))
		{
			ans=mid;
			lb=mid+1;
		}

		else
			ub=mid-1;
	}

	return ans;
}


int main()
{
	int N, C, *a;
	cin>>N>>C;

	a = new int[N];
	for(i=0; i<N; i++)
		cin>>a[i];

	cout<<agr_cow(a,N,C);

	delete[] a;
	return 0;
}