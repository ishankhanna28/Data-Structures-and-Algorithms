#include <iostream>
using namespace std;

//Write a recursive function to find product of 2 integers without using arithematic '*' operator.

int PROD(int a, int b)
{
	if(!b)
		return 0;

	else 
		return a + PROD(a,b-1);
}


int main()
{
	cout<<PROD(7,8)<<endl;
	return 0;
}