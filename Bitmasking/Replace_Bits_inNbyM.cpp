#include <iostream>
using namespace std;

/*
Adobe
You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits 
between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output:N = 10001010100
Note: Input and Output should be in decimal format(not in binary as is given in above example).
*/ 


int clear_rangeOFbits(int n, int i, int j)
{
	return n & ( ((-1)<<(j+1)) | ((1<<i)-1) );
}

int replace_bit(int n, int m, int i, int j)
{
	return clear_rangeOFbits(n,i,j) | (m<<i) ;
}

int main()
{
	int N, M, I, J;
	cin>>N>>M>>I>>J;

	cout<<replace_bit(N,M,I,J);
	return 0;
}
