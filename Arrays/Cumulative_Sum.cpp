#include<iostream>
using namespace std;
int i;

int Cumulative_Sum(int A[], int N)
{
	int j, LB, UB, cur_sum, max_sum =A[0], *cum_sum = new int[N];

	cum_sum[0]=A[0];
	for(i=1; i<N; i++)
		cum_sum[i] = A[i] + cum_sum[i-1];

	for(i=0; i<N; i++)
	{
		for(j=i; j<N; j++)
		{
			cur_sum = cum_sum[j] - cum_sum[i-1];
			if(cur_sum > max_sum)
			{
				max_sum=cur_sum;
				LB=i;
				UB=j;
			}
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

	sum=Cumulative_Sum(a,n);
	cout<<"(Maximum Sum = "<<sum<<" )";
	return 0;
}