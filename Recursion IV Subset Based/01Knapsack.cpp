#include <iostream>
using namespace std;


int PROFIT(int p[], int w[], int c, int n)
{
	if(n<0 || !c)
		return 0;

	int inc, exc;
	inc=exc=0;

	if(w[n]<=c)
		inc = p[n] + PROFIT(p, w, c-w[n], n-1);

	exc = PROFIT(p, w, c, n-1);

	return max(inc, exc);
}


int main()
{
	int K, N;
	cin>>K>>N;

	const int K1 = N;
	int wt[K1], pr[K1];

	for(int i=0; i<N; i++)
		cin>>pr[i]>>wt[i];

	cout<<PROFIT(pr, wt, K, N-1);
}