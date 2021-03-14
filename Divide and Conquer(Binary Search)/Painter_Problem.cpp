#include<iostream>
using namespace std;


int can_paint(int a[], int boards, int painters, int time, int max_time)
{
	int i=0, count=1, sum=0;

	while(i<boards)
	{
		if(sum + a[i]*time <= max_time)
		{
			sum+= a[i++]*time;
		}

		else
		{
			count++;
			
			if(count>painters)
				return false;

			else
				sum=0;
		}
	}
	return true;
}


int Painter(int a[], int n, int k, int t, int lb, int ub)
{
	int mid, ans;
	lb*=t;
	ub*=t;

	while(lb<=ub)
	{
		mid=(lb+ub)/2;

		if(can_paint(a,n,k,t,mid))
		{
			ans=mid;
			ub=mid-1;
		}

		else
		{
			lb=mid+1;
		}		
	}

	return ans%10000003;
}


int main()
{
	int N, K, T, *A, i, SUM=0, MAX=0;
	cin>>N>>K>>T;
	A=new int[N];

	for(i=0; i<N; i++)
	{
		cin>>A[i];

		SUM+=A[i];
		MAX=max(MAX,A[i]);
	}

	cout<<Painter(A,N,K,T,MAX,SUM);

	delete[] A;
	return 0;
}