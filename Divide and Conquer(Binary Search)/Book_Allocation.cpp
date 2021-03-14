#include<iostream>
using namespace std;


bool can_be_distributed(int A[], int N, int s, int max)
{
	int pages=0, i;

	for(i=0; i<N; i++)
	{
		if(pages + A[i] <= max)
			pages+=A[i];

		else
		{
			pages=0;
			i--;
			s--;

			if(!s)
				return false;
		}
	}

	return true;
}


int book_alloc(int A[], int N, int S, int lb, int ub)
{
	int ans, mid;

	while(lb<=ub)
	{
		mid=(lb+ub)/2;

		if(can_be_distributed(A,N,S,mid))
		{
			ans=mid;
			ub=mid-1;
		}

		else
		{
			lb=mid+1;
		}
	}

	return ans;
}


int main()
{
	int t, n, m, **a, r, c, MAX, SUM;
	cin>>t;
	a=new int*[t];

	for(r=0; r<t; r++)
	{
		MAX=0, SUM=0;
		cin>>n>>m;
		a[r]= new int[n];

		for(c=0; c<n; c++)
		{
			cin>>a[r][c];

			MAX=max(MAX,a[r][c]);
			SUM+=a[r][c];
		}

		cout<<book_alloc(a[r],n,m,MAX,SUM)<<endl;
	}

	for(r=0; r<t; r++)
		delete[] a[r];

	delete[] a;
	return 0;
}


/*
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90
Sample Output
113 
Explanation
1st students : 12 , 34, 67 (total = 113)
2nd students : 90 (total = 90)
Print max(113, 90)
*/