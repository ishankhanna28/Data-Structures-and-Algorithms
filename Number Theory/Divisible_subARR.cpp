#include <iostream>
using namespace std;
#define int long long
#define INT int
//Pigeonhole principle



int div_sub(int a[], const int n)
{
	int pre[n], fre[n]={0}, i, count=0;
	pre[0]=0;	//pre[0]=a[0]

	for(i=1; i<n; i++)
		pre[i]= (pre[i-1] + a[i] + (n-1) )%(n-1);	//N=n-1	//+(n-1) is to avoid negative

	//Before taking mod in cumulative sum array...
	//(pre[i]-pre[j]) represents sums of various subarrays of given array for different value of i&j (i>j)
	//For (pre[i]-pre[j])%(N)=0; pre[i]%N=pre[j]%N

	//If N=5 --> x%N = {0, 1, 2, 3, 4}
	//   n=6 --> 6 containers
	//fre[i] = frequency of i in pre array

	for(i=0; i<n; i++)
		fre[pre[i]]++;

	for(i=0; i<n; i++)
		if(fre[i]>1)
			count+= (fre[i]*(fre[i]-1))/2;	//PNC fre[i]C2

	return count;
}


void solve()
{
	int i, N, *A;
	cin>>N;
	A= new int[N+1];
	A[0]=0;

	for(i=1; i<=N; i++)
		cin>>A[i];

	cout<<div_sub(A, N+1)<<endl;;
	delete[] A;
}


int32_t main()
{
	int T=1;
	cin>>T;

	while(T--)
		solve();

	return 0;
}