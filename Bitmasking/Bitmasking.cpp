#include <iostream>
using namespace std;


bool is_odd(int n)	//For odd no. rightmost bit (0th bit) is 1					
{					//(int &n)
	return (n&1);
}


int get_bit(int n, int i)	//Returns the i^th bit.
{
	return (n&(1<<i)) ?1:0;
}


int set_bit(int n, int i)	//Set i^th bit to 1
{
	return n|(1<<i);
}

int clear_bit(int n, int i)	//Set i^th bit to zero
{
	return n & ~(1<<i);
}

int update_bit(int n, int i, int b)
{
	return clear_bit(n,i) | (b<<i);
}

int clear_lastIbits(int n, int i)
{
	return n & ((-1)<<i);
}

int clear_rangeOFbits(int n, int i, int j)
{
	return n & ( ((-1)<<(j+1)) | ((1<<i)-1) );
}


int main()
{
	if(is_odd(72))
		cout<<"Odd no."<<endl;

	else 
		cout<<"Even no."<<endl;

	cout<<get_bit(5,2)<<endl;
	cout<<set_bit(5,1)<<endl;
	cout<<clear_bit(7,1)<<endl;
	cout<<update_bit(9,2,1)<<endl;
	cout<<~0<<endl;
	cout<<clear_lastIbits(15,2)<<endl;
	cout<<clear_rangeOFbits(31,1,3)<<endl;
	





	return 0;
}



