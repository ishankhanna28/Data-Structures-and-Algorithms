#include<iostream>
using namespace std;
int i;

int SubARR(int A[], int N)
{
	int j, k, LB, UB, cur_sum, max_sum=A[0], count=0;
	cout<<endl<<"The Subarrays of the given Array are..."<<endl;

	for(i=0; i<N; i++)
	{
		for(j=i; j<N; j++)
		{
			cur_sum=0;
			count++;

			for(k=i; k<=j; k++)
			{
				cout<<A[k]<<", ";
				cur_sum+=A[k];
			}
		cout<<"\b"<<" (Sum of Subarray #"<<count<<" = "<<cur_sum<<" )"<<endl;

		if(cur_sum>max_sum)
		{
			max_sum=cur_sum;
			LB=i;
			UB=j;
		}
		}

	}

	cout<<"No. of Subarrays = "<<count<<endl;
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

	sum=SubARR(a,n);
	cout<<"(Maximum Sum = "<<sum<<" )";
	return 0;
}