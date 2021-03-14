#include <iostream>
using namespace std;

//Using Property... LCM(a,b) x HCF(a,b) = axb
//The product of HCF and LCM of 2 natural numbers is eual to the product of the 2 numbers

int HCF(int a, int b)	//b>a
{
	return (b%a)? HCF(b%a,a) :a;
}

int LCM(int A, int B)	//B>A
{
	return (A*B)/HCF(A,B);
}

int main()
{
	int x, y;
	cin>>x>>y;

	cout<<LCM(min(x,y), max(x,y));
	return 0;
}

/*
Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the LCM of N1 and N2. Print the value returned.

Input Format
Constraints
0 < N1 < 1000000000 0 < N2 < 1000000000

Output Format
Sample Input
4 
6
Sample Output
12
Explanation
The smallest number that is divisible by both N1 and N2 is called the LCM of N1 and N2.
*/