#include <iostream>
#include <unordered_set>
using namespace std;


bool CheckSub(int a[], int n)
{
	unordered_set<int> s;
	s.insert(0);
	int pre=0;

	for(int i=0; i<n; i++)
	{
		pre+=a[i];

		if(s.find(pre)!=s.end())
			return true;

		s.insert(pre);
	}

	return false;
}


int main()
{
	int a[]= {6, -1, 2, 1, -1, 3};
	int n = sizeof(a)/sizeof(int);

	if(CheckSub(a,n))
		cout<<"true"<<endl;

	else
		cout<<"false"<<endl;
	return 0;
}