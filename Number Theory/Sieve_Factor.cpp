#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vp vector<pair<int,int>>
#define ff first
#define ss second

//Pre computation time: N*log(log(N))
//Each query is computed in: logN time.


void Prime_Sieve(int a[],int n)	//if (a[i]==1) ==> i is prime 
{								//excluding n (1 to n-1)
	int i, j;
	a[2]++;

	for(i=3; i<n; i+=2)
		a[i]++;


	for(i=3; i<n; i+=2)
	{
		if(a[i])
		{
			for(j=i*i; j<n; j+=i)
			{
				if(j%2 && a[j])
					a[j]--;
			}
		}
	}
}


vi Get_Primes(int max_prime)
{
	const int N = max_prime +1;
	int i, A[N] = {0};

	Prime_Sieve(A,N);
	vi primes;
	primes.reserve(20);
	primes.clear();

	for(i=0; i<N; i++)
		if(A[i])
			primes.push_back(i);

	return primes;
}


vp Fatcorize(int n, vi pr)
{
	int cnt;
	vp v;

	for(auto i:pr)
	{
		if(i*i>n)
			break;

		cnt=0;

		while(n%i==0)
		{
			cnt++;
			n/=i;
		}

		if(cnt)
			v.push_back(make_pair(i,cnt));
	}

	if(n!=1)
		v.push_back(make_pair(n,1));

	return v;
}


int main()
{
	int T, num;
	vi pri;
	cin>>T;	//T=No. of Test cases. T numbers inputted(largest number must be inputted first)
	const int k=T;

	while(T)
	{
		cin>>num;

		if(T==k)
			pri = Get_Primes(sqrt(num));

		vp V = Fatcorize(num,pri);
		cout<<"1";

		for(auto x:V)
		{
			cout<<" x "<<x.ff;

			if(x.ss>1)
				cout<<"^"<<x.ss;
		}

		cout<<endl;
		T--;
	}

	return 0;
}
