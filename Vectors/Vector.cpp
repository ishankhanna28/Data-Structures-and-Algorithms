#include<iostream>
#include<vector>
using namespace std;


int main()
{
	//Vector is a dynamic array(can shrink & grow in size)
	//Vector can double no. of elements upto a certain limit

	//Declare and initialise a vector
	vector<int> v;
	vector<int> a(5,10); //Creates a vector of elements and initialises each element as 10. 
						//Useful to create null vector of n elements vector<int> v(n,0);
	vector<int> b{10,20,30};
	vector<int> c(b.begin(),b.end()); //c is a copy of b


	//Input Vector elements from user.

	int n, i, num;
	cin>>n;

	for(i=0; i<n; i++)
	{
		cin>>num;
		v.push_back(num);//doubles the capacity of a vector. Expansion of capacity is an expensive process. (avoid)
	}



	//Iterate over the Vector

	for(i=0; i<a.size(); i++)
		cout<<a[i]<<" ";
	cout<<endl;

	for(auto it=c.begin(); it<c.end(); it++) //v.begin() & v.end() return pointers to first and last elements of the vector.
		cout<<(*it)<<" "; //it is iterator of type vector<int>::iterator (auto)
	cout<<endl;

	for(int x:v) //For each integer x such that it is an element of vector v
		cout<<x<<" ";
	cout<<endl<<endl;



	//Comparing size of a and v
	cout<<a.size()<<endl;	 //No. of elements which have been allocated
	cout<<a.capacity()<<endl;//No. of elements which can be filled without further expansion
	cout<<a.max_size()<<endl;//Upper limit of no. of elements vector can contain after which no further expansion can happen
	cout<<endl<<endl;

	cout<<v.size()<<endl;	 //No. of elements which have been allocated
	cout<<v.capacity()<<endl;//No. of elements which can be filled without further expansion
	cout<<v.max_size()<<endl;//Upper limit of no. of elements vector can contain after which no further expansion can happen

	return 0;
}



/*
Input

5
11 22 33 44 55
*/


/*
Output

10 10 10 10 10 
10 20 30 
11 22 33 44 55 

5
5
2305843009213693951

5
8
2305843009213693951
*/