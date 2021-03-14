#include <iostream>
using namespace std;


bool is_sorted(int a[], int n)
{
	if(!n)
		return true;

	else if(a[n-1] > a[n])
		return false;

	else
		return is_sorted(a,n-1);
}


int main()
{
	int N, *A, i;
	cin>>N;
	A=new int[N];

	for(i=0; i<N; i++)
		cin>>A[i];

	if(is_sorted(A,N-1))
		cout<<"true";

	else
		cout<<"false";

	delete[] A;
	return 0;
}