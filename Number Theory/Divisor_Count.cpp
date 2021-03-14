//WAP to print the no. of divisors of a given integer
//60 = 2^2 x 3^1 x 5^1
//No. of divisors = (2+1)(1+1)(1+1) = 12 (PNC None or more selection)

#include <iostream>
#include<vector>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vp vector<pair<int,int>>
#define ff first
#define ss second

//O(sqrt(n))

int Divize(int n)
{
	int i, cnt, ans=1;

	for(i=2; i*i<=n; i++)
	{
		cnt=0;

		while(n%i==0)
		{
			cnt++;
			n/=i;
		}

		ans*= (cnt+1);
	}

	if(n!=1)
		ans*=2;	//Remaining prime is also a divisor with power = 1. Hence, multiply by 1+1=2
		
	return ans;
}


int main()
{
	int num=60;
//	cin>>num;
	cout<<Divize(num)<<endl;
	return 0;
}