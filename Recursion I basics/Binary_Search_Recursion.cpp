#include <iostream>
using namespace std;


int Binary_Search(int a[], int m, int lb, int ub)
{
	int mid = (lb+ub)/2;

	if(lb>ub)
		return -1;

	else if(a[mid]==m)
		return mid;

	else if(a[mid]<m)
		return Binary_Search(a, m, mid+1, ub);

	else 
		return Binary_Search(a, m, lb, mid-1);

}


int main()
{
	int N, M, *A, i;
	cin>>N;
	A=new int[N];

	for(i=0; i<N; i++)
		cin>>A[i];

	cin>>M;
	cout<<Binary_Search(A, M, 0, N-1);
	return 0;
}