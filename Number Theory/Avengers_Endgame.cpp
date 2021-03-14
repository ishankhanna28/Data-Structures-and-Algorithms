#include <iostream>
using namespace std;
//https://hack.codingblocks.com/app/practice/1/1264/problem
//Since, n is large we use PRINCIPLE OF INCLUSION-EXCLUSION to avoid TLE
//O(Nxlog(N)) complexity where N=2^8=(1<<8)


void solve()
{
	long long a[]={2, 3, 5, 7, 11, 13, 17, 19}, i, n, t, j, denom, ans=0;
	cin>>n;

	for(i=1; i<(1<<8); i++)
	{
		denom=1;
		t=i;
		j=0;

		while(t)
		{
			if(t&1)
				denom*=a[j];

			j++;
			t= t>>1;
		}

		if(__builtin_popcount(i)%2)
			ans+= n/denom;

		else 
			ans-= n/denom;
	}

	cout<<ans<<endl;
}


int main()
{
	int T=1;
	cin>>T;

	while(T--)
		solve();

	return 0;
}

/*
AVENGERS END GAME

After the release of Avengers, Ironman and Thor got into a fight and Ironman challenged Thor to find out the number of numbers between 1 and n which are divisible by any of the prime numbers less than 20. Ironman being great at maths quickly answered the question but then Thor asked him to write a program for it. Ironman however found it quite difficult as he did not wanted to write so many lines of code. he knows that you are smart and can code this up easily. Can you do it?

Input Format
The first line consists of number of test cases t. then follow t lines which consists of number n for each test case.

Constraints
1 <= test cases <= 10 1 <= n <= 10^18

Output Format
the answer to each test case each in different line

Sample Input
5
5
10
12
15
18
Sample Output
4
9
11
14
17
Explanation
for n = 5 2 and 4 are divisible by 2 and 3 is divisible by 3 and 5 by 5. hence ans = 4.
*/