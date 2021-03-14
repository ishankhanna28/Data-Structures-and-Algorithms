#include <iostream>
using namespace std;
//16 = 10000

int count_set_bits(int n) //O(logn + 1)	
{						   //log is to the base 2 
	int count=0;

	while(n)
	{
		count+=n&1;	
		n=n>>1;
	}

	return count;
}


int count_set_bits_fast(int n) //O(N) where N=No. of set bits of num <= log(num)= no. of bits
{
	int count=0;

	while(n)
	{
		n= n&(n-1); //each iteration will elimintae one set bit
		count++;    //ans is no. of times loop executes
	}

	return count;
}

/*
n= n&(n-1)
3

 13 = 1101
&12 = 1100
___________
 12	= 1100
&11 = 1011
___________
  8 = 1000
 &7 = 0111
 __________ 
  0	= 0000

  1101
 -   1
 ______
  1100

  1100
 +1111
  _____
  1011
*/

int main()
{
	int N, num;
	cin>>N;

	for(; N; N--)
	{
		cin>>num;
		cout<<__builtin_popcount(num)<<endl; 	//Inbuilt function 
	}

	return 0;
}

/*
count number of 1s in binary representation of an integer

Input Format
Input N = Number of Test Cases, followed by N numbers

Constraints
Output Format
Number of Set Bits in each number each in a new line

Sample Input
3
5
4
15
Sample Output
2
1
4
Explanation
Convert Binary to Decimal first and then count number of 1's present in all digits.
*/