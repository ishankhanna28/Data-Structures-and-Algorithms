#include <iostream>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second


void Prime_Sieve(int a[],ll n)	//if (a[i]==1) ==> i is prime 
{								//excluding n (1 to n-1)
	ll i, j;
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


int Prime_Visits(ll a, ll b, int arr[])
{
	int count=0;

	for(ll i=a; i<=b; i++)
		if(arr[i])
			count++;

	return count;
}


int main()
{
	ll N, I, a, b, MAX=0;
	cin>>N;
	pii* p = new pii[N];

	for(I=0; I<N; I++)
	{
		cin>>p[I].ff>>p[I].ss;
		MAX=max(MAX, p[I].ss);
	}

	const ll max=MAX+1;
	int A[max]={0};
	Prime_Sieve(A,max);


	for(I=0; I<N; I++)
		cout<<Prime_Visits(p[I].ff, p[I].ss, A)<<endl;

	delete[] p;
	return 0;
}

/*
PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country , So PM Modi decides to visit only those countries,for which country number has two divisors. So your task is to find number of countries Mr. Modi will visit.



Input Format
The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

Constraints
a<=1000000 & b<=1000000.
N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

Sample Input
2
1 10
11 20
Sample Output
4
4
Explanation
PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
For the second testcase , he chooses countries with numbers 11,13,17 and 19.
*/