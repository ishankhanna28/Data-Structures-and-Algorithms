#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	Vector<char> v;
	char ch= 'a';

	if(v.Empty())
		v.Reserve(4);

	for(int i=0; i<4; i++)
	{
		v.Push_Back(ch++);
		cout<<"Size = "<<v.Siz()<<endl;	 
		cout<<"Capacity = "<<v.Capacity()<<endl;
	}

	for(auto it=v.Begin(); it<v.End(); it++)
		cout<<*it<<" ";

	v.Pop_Back();
	cout<<endl;
	cout<<"Size = "<<v.Siz()<<endl;	 
	cout<<"Capacity = "<<v.Capacity()<<endl;
	cout<<endl<<"First Element = "<<v.Front()<<endl;
	cout<<"Last Element = "<<v.Back()<<endl;

	v.Resize(7);
	cout<<v.Siz()<<endl;
	cout<<v[0]<<endl;

	for(int i=0; i<3; i++)
		cout<<v[i]<<" ";

	cout<<endl;
	return 0;
}
