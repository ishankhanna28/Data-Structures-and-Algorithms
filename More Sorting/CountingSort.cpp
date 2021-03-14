#include<iostream>
using namespace std;

//O(N + Range) complexity
//Can be used when range is small, O(N) aprox.


void CountSort(int a[], int n)
{
	int Max=a[0];

	for(int i=1; i<n; i++)
		Max=max(Max, a[i]);

	const int K1 = Max+1;
	int cnt[K1]={0};

	for(int i=0; i<n; i++)
		cnt[a[i]]++;

	for(int i=0, j=0; i<K1; i++)
		while(cnt[i]--)
			a[j++]=i;


}


int main()
{
	int N;
	cin>>N;

	const int K2=N;
	int A[K2];

	for(int i=0; i<N; i++)
		cin>>A[i];

	CountSort(A, N);

	for(int i=0; i<N; i++)
		cout<<A[i]<<" ";

	cout<<endl;
	return 0;
}