#include <iostream>
using namespace std;


bool is_bit_set(int n, int POS)	//Returns the i^th bit.
{
	return (n&(1<<POS)) ?true :false;
}


int first_set_bit(int n)
{
	int c=0;

	while(n&1==0)
	{
		c++;
		n = n>>1;
	}

	return c;
}


int main()
{
	int n, *a, i, x=0, y, ans=0, pos;
	cin>>n;
	a = new int[n];

	for(i=0; i<n; i++)
	{
		cin>>a[i];
		ans=ans^a[i];
	}

	pos= first_set_bit(ans);

	for(i=0; i<n; i++)
	{
		if(is_bit_set(a[i],pos))
			x= x^a[i];
	}

	y = x^ans;
	cout<<min(x,y)<<" "<<max(x,y);

	delete[] a;
	return 0;
}

/*
We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1
Sample Output
2 3
Explanation
Smaller number comes before larger number
*/