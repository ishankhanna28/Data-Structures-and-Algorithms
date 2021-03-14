#include <iostream>
using namespace std;

//Using Euclid's algorithm
//implement with recursion

int HCF(int a, int b)	//b>a
{
	return (b%a)? HCF(b%a,a) :a;
}


int main()
{
	int x, y;
	cin>>x>>y;

	cout<<HCF(min(x,y), max(x,y));
	return 0;
}

/*
Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the GCD of N1 and N2. Print the value returned.



Input Format
Two integers seperated by a new line.

Constraints
0 < N1 < 1000000000
0 < N2 < 1000000000

Output Format
Output a single integer which is the GCD of the given integers.

Sample Input
16 
24
Sample Output
8
Explanation
The largest number that divides both N1 and N2 is called the GCD of N1 and N2.
*/