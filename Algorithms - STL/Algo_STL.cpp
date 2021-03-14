#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a>=b;
}

int main()
{
	int A[]={22,44,11,99,44,33,77,44,88,66,55};
	int n = sizeof(A)/sizeof(int);
	int key = 100;

	auto it = find(A,A+n,key);	//datatype of it is int*
	cout<<it<<endl;
	int index = it-A;

	if(index<n)
		cout<<index<<endl;

	else 
		cout<<"Element is absent"<<endl;


	cout<<endl;
	sort(A,A+n); 	//11, 22, 33, 44, 44, 44, 55, 66, 77, 88, 99
	key = 45;
	bool found = binary_search(A,A+n,key);

	/*
	if(!found)
		cout<<"NOT FOUND"<<endl;
	*/

//	else
	{
		auto lb = lower_bound(A,A+n,key);	//returns pointer to address of first element of array >=key 
		cout<<lb<<endl;
		cout<<lb-A<<endl;

		auto ub = upper_bound(A,A+n,key);	//returns pointer to address of first element strictly greater than (>) key
		cout<<ub<<endl;
		cout<<(ub-A)<<endl;

		if(ub==lb)
			cout<<"ABSENT!"<<endl;

		else
			cout<<"Frequency of occuerence = "<<(ub-lb)<<endl;
	}

	cout<<endl;
	int b[]={11, 22, 33, 44, 55, 66, 77, 88, 99};
	int N = sizeof(b)/sizeof(int);

	key = 22;
	int lb = lower_bound(b, b+N, key, compare) - b;
	cout<<lb<<endl;
	
	return 0;
}