//WAP to print the sum of all divisors of a given integer
//60 = 2^2 x 3^1 x 5^1
// Sum = (2^0 + 2^1 + 2^2) x (3^0 + 3^1) x (5^0 + 5^1) = 


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

//O(sqrt(n))

vp Fatcorize(int n)
{
	int i, cnt;
	vp v;

	for(i=2; i*i<=n; i++)
	{
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
	int num=60, ans=1, sum;
//	cin>>num;
	vp V=Fatcorize(num);

	for(auto x:V)
	{
		sum=0;

		while(x.ss>=0)
		{
			sum+= pow(x.ff,x.ss);
			x.ss--;
		}

		ans*=sum;
	}

	cout<<ans<<endl;
	return 0;
}
