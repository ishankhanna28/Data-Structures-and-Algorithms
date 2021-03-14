#include<iostream>
using namespace std;


bool can_make_prata(int r[], int l, int p, int max_time)
{
	int i, time, t;

	for(i=0; i<l; i++)
	{
		time=0;
		t=1;

		while(time + (t*r[i]) <= max_time)
		{
			time += t*r[i];
			p--;

			if(!p)
				return true;

		    t++;
		}
	}

	return false;
}


int Prata(int r[], int l, int p, int max)
{
	int lb=0, mid, ans;
	int ub=p*(p+1)*max;
	ub/=2;

	while(lb<=ub)
	{
		mid=(lb+ub)/2;

		if(can_make_prata(r, l, p, mid))
		{
			ans=mid;
			ub=mid-1;
		}

		else
		{
			lb=mid+1;
		}
	}

	return ans;
}


int main()
{
	int T, P, L, **R, i, j, MAX;
	cin>>T;
	R=new int*[T];

	for(i=0; i<T; i++)
	{
		MAX=0;
		cin>>P>>L;
		R[i]=new int[L];

		for(j=0; j<L; j++)
		{
			cin>>R[i][j];
			MAX=max(MAX,R[i][j]);
		}

		cout<<Prata(R[i], L, P, MAX)<<endl;
		delete[] R[i];
	}

	delete[] R;
	return 0;
}