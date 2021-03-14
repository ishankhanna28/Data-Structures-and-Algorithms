#include<iostream>
using namespace std;
int i;

int Kadane_Algo(int A[], int N)
{
	int t=0, LB=0, UB=0, cum_sum=0, max_sum=A[0]; 

	for(i=0; i<N; i++)
	{
		cum_sum+=A[i];

		if(cum_sum<0)
		{
			cum_sum=0;
			t=i+1;
		}

		else if(cum_sum>max_sum)
		{
			max_sum=cum_sum;
			UB=i;
			LB=t;
		}
	}

	cout<<endl<<"The Subarray having maximum sum is..."<<endl;
	for(i=LB; i<=UB; i++)
		cout<<A[i]<<"  ";
	cout<<endl;

return max_sum;
}

int main()
{
	int  sum, n, *a;

	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;
	a = new int[n];

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>a[i];

	sum=Kadane_Algo(a,n);
	cout<<"(Maximum Sum = "<<sum<<" )";

	delete[] a;
	return 0;
}