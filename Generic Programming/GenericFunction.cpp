//Linear Search (first occurrence)
//We can implement Generic Function (valid for containers of all datatypes using STL Template)
//Iterators allow function for all types of containers.
#include <iostream>
#include <vector>
using namespace std;

template<class ite, class t> 	//OR we can say template<typename a, typename b>
ite LinearSearch(ite beg, ite end, t key)
{
	for(auto it=beg; it!=end; it++)
		if(*it==key)
			return it;

	return end;
}


void IntArr()
{
	int A[] = {22, 44, 11, 55, 66, 77, 82, 75};
	int N = sizeof(A)/sizeof(int);
	int key = 55;
	
	auto it = LinearSearch(A, A+N, key);
	if(it==A+N)
		cout<<-1<<endl;
	else
		cout<<it-A<<endl;
}


void FloatArr()
{
	float A[] = {22.5, 44.7, 11.8, 55.1, 66.0, 77.7, 82.3875, 75.24};
	int N = sizeof(A)/sizeof(int);
	float key = 77.7;
	
	auto it = LinearSearch(A, A+N, key);
	if(it==A+N)
		cout<<-1<<endl;
	else
		cout<<it-A<<endl;
}


void Vect()
{
	int key = 63;
	vector<int> v;
	v.push_back(12);
	v.push_back(1);
	v.push_back(8);
	v.push_back(42);
	v.push_back(63);
	v.push_back(18);
	v.push_back(36);

	auto it = LinearSearch(v.begin(), v.end(), key);
	if(it==v.end())
		cout<<-1<<endl;
	else
		cout<<it-v.begin()<<endl;


}


int main()
{
	IntArr();
	FloatArr();
	Vect();
	return 0;
}