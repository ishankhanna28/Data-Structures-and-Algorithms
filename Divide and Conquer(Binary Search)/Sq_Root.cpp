#include<iostream>
using namespace std;

float sq_root(float n, int p)
{
	int lb=0, ub=n, mid, i;

	while(lb<=ub)
	{
		mid=(lb+ub)/2;

		if(mid*mid<n)
			lb=mid+1;

		else if(mid*mid>n)
			ub=mid-1;

		else
			return mid;
	}


	float ans=(mid-1), inc=0.1;

	for(i=1; i<=p; i++)
	{
		while(ans*ans<n)
			ans+=inc;
		
		if(ans*ans==n)
			return ans;

		else
			ans-=inc;	//Have overshot

		inc/=10;
	}

	return ans;
}


int main()
{
	float N;
	int P;

	cout<<"\tSQUARE ROOT CALCULATOR"<<endl;
	cout<<"Input a positive no..."<<endl;
	cin>>N;
	cout<<"Input precision(upto how many decimal floating points you want to calculate square root)..."<<endl;
	cin>>P;
	cout<<"Square root of "<<N<<" = "<<sq_root(N,P);

	return 0;
}
