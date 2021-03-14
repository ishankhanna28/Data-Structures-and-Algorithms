#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int a[] = {10,20,30,40,50};	//30 40 50 10 20
	int n=sizeof(a)/sizeof(int),i;
	rotate(a,a+2,a+n); //Read array starting from 2nd subscript in cyclic order

	for(i=0; i<n; i++)
		cout<<a[i]<<" ";


	cout<<endl;
	vector<int> v{12,24,36,48,60};

	rotate(v.begin(), v.begin()+3, v.end());

	for(i=0; i<v.size(); i++)
		cout<<v[i]<<" ";

	/*			3x2x1= 3! = 6
	{1,2,3} --> _ _ _
	The 6 combinations in lexiographic order(asc)...
	123
	132
	213
	231
	312
	321
	*/
	cout<<endl;
	int A[] = {3,2,1};
	n = sizeof(A)/sizeof(int);
	next_permutation(A,A+n); //rearranges to lexiographically next permutation. 
							 //	If already at largest no. goes to smallest

	for(i=0; i<n; i++)
		cout<<A[i]<<" ";


	cout<<endl;
	vector<int> v1{1,3,2};
	next_permutation(v1.begin(),v1.end());

	for(int x:v1)
		cout<<x<<" ";


	cout<<endl;
	int b[]={10,20,30,40,50};
	n=sizeof(b)/sizeof(int);
	
	reverse(b,b+3);	//reverses first 3 elements of the array
	swap(b[3],b[4]); 

	for(i=0; i<n; i++)
		cout<<b[i]<<" ";
	cout<<endl<<endl;

	pair <int,char> p1 = make_pair(3,'a');
	pair <int,char> p2(p1);
	pair <pair<int,char>,string> p = make_pair(p2,"For Apple");

	cout<<p.first.first<<endl;
	cout<<p.first.second<<endl;
	cout<<p.second<<endl;

	cout<<endl;
	return 0;
}