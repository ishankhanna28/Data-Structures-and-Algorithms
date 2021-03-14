#include <iostream>
#include <algorithm>
using namespace std;


int MoneyChange(int a[], int n, int mon)
{
	int cnt=0;

	while(mon)
	{
		int idx = upper_bound(a, a+n, mon) - 1 - a;
		cout<<a[idx];

		cnt++;
		mon-=a[idx];

		if(mon)
			cout<<" + ";
	}

	cout<<endl;
	return cnt;
}


int main()
{
	int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int n = sizeof(a)/sizeof(int);
	int money = 39;

	cout<<MoneyChange(a,n, money)<<" coins"<<endl;
	return 0;
}