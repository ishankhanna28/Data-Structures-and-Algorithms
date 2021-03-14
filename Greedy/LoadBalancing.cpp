#include <iostream>
#include <vector>
using namespace std;

//https://www.spoj.com/problems/BALIFE/


int LoadBal(vector<int> v, int n, int sum)
{
	if(sum%n!=0)
		return -1;

	int dif=0, ans=-1, load=sum/n;

	for(int i=0; i<n; i++)
	{
		dif+= v[i]-load;
		ans=max(ans, abs(dif));
	}

	return ans;
}


int main()
{
	vector<int> v;
	int n=0, num;

	while(true)
	{
		cin>>n;

		if(n==-1)
			break;

		v.reserve(n);
		int sum=0;

		for(int i=0; i<n; i++)
		{
			cin>>num;
			v.push_back(num);
			sum+=num;
		}

		cout<<LoadBal(v,n,sum)<<endl;
		v.clear();
	}

	return 0;
}