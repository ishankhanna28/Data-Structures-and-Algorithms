#include <iostream>
using namespace std;

int main()
{
	int n=3, i, j, t;
	char str[]="abc";

	for(i=0; i<(1<<n); i++)
	{
		t=i;
        j=0;

		while(t)
		{
			if(t&1)
				cout<<str[j];

			t=t>>1;
			j++;
		}

		cout<<endl;
	}

	return 0;
}

//WAP 
to Generate all possible subsets of a given string

/*
Sample Input:
3
abc

Sample Output:

a
b
c
ab
bc
ac
abc
*/

/*
ac is not a substring(continuous) but is a subset

a b c
_ _ _
2x2x2 =8 subsets (2 possibilities--> either part of the subset or not)
0 0 0 = 0
0 0 1 = 1
.
.
.
1 1 1 =7 (2 to the power n -1)
*/