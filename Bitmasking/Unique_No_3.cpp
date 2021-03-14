#include <iostream>
using namespace std;

void set_bit(int *n, int POS)	//Set i^th bit to 1
{
	*n= *n|(1<<POS);
}

int main()
{
	int n, *a, i, j, sum, num=0, count;
	cin>>n;
	a=new int[n];

	for(i=0; i<n; i++)
		cin>>a[i];

	for(i=0; i<32; i++)	//for each bit
	{
		sum=0;
		count=0;

		for(j=0; j<n; j++) //for each array element a[j]
		{
			if(a[j])
			{
				sum+= (a[j]&1);	//adding last bit
				a[j]=a[j]>>1;	//right shifting the last bit out
				count++;
			}
		}

		if(sum%3)
			set_bit(&num,i);

		if(!count)
			break;
	}

	cout<<num;
	delete[] a;
	return 0;
}

/*
We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. Find the unique number. Only use - bitwise operators, and no extra space.

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
N < 10^5

Output Format
Output a single line containing the unique number

Sample Input
7
1 1 1 2 2 2 3
Sample Output
3
Explanation
3 is present only once
*/

/*
a[]={1, 1, 1, 2, 2, 2, 3};

1 = 01
1 = 01
1 = 01
2 = 10
2 = 10
2 = 10
3 = 11
_______
     3

for a particular bit position, some of all bits, can be of 2 types:-
where N is an integer

1) 3N
3) 3N+1
*/