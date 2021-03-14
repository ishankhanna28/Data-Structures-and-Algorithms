#include <iostream>
#include <cstring>
using namespace std;

//Functor is a Functional Operator overloaded object of a Class
//Round bracket operator is used

class Fun
{
	public:

	void operator()(string str)
	{
		cout<<"Hello "<<str<<endl;
	}
};


int main()
{
	Fun f;
	f("C++");
	return 0;
}