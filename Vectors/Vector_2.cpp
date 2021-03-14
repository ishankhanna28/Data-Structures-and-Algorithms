#include<iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v{11,22,33,44,55};

	v.pop_back(); 	//deletes the last element of the vector
	//Both push_back(int) and pop_back() have O(1) complexity


	//Insert or erase no. from middle of vector 
	v.insert(v.begin()+2, 2, 99); //O(5)
	v.erase(v.end()-2);
	//v.insert() and v.erase() functions operate in O(n) complexity
	//n= no. of elements inserted + no. of elements shifted

//	v.clear(); //Deletes elements of the vector but doesn't deallocate its memory

	if(v.empty())
		cout<<"Vector is empty"<<endl;

	else 
		cout<<"Vector is not empty"<<endl;

	v.resize(4); 
	//Changes both capacity and size to argument.
	//Expands vector and initialises all new elements to zero
	//When used to contract, changes only size not capacity (AVOID)

	for(int x:v)
		cout<<x<<" ";
	//11 22 99 99 

	cout<<endl;
	cout<<"First Element "<<v.front()<<endl;
	cout<<"Last Element "<<v.back()<<endl;


	cout<<endl<<"Size = "<<v.size()<<endl;	 
	cout<<"Capacity = "<<v.capacity()<<endl;
	cout<<"Max Size = "<<v.max_size()<<endl;

	return 0;
}