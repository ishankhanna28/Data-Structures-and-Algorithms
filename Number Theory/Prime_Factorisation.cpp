#include <iostream>
#include<vector>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vp vector<pair<int,int>>
#define ff first
#define ss second

//O(sqrt(n)*logn)

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
	int num=289;
//	cin>>num;
	vp V=Fatcorize(num);
	cout<<"1";

	for(auto x:V)
	{
		cout<<" x "<<x.ff;

		if(x.ss>1)
			cout<<"^"<<x.ss;
	}

	cout<<endl;
	return 0;
}