#include<iostream>
#include<algorithm>
using namespace std;
int i, j;

int Two_Ptr(int A[], int N, int num)
{
	int sum=0, count=0;
	i=0;
	j=N-1;

	while(i<j)
	{
		sum = A[i] + A[j];

		if(sum<num)
			i++;

		else if(sum>num)
			j--;

		else
		{
//			if(count++==0) cout<<endl<<"The Pairs of elements of given array whoose sum = "<<num<<" are ..."<<endl;
//			cout<<count<<") ";
			cout<<A[i]<<" and "<<A[j]<<endl;
			i++;
			j--;
		}
	}

return count;
}

/*
int Sort_Check(int a[], int size)
{int s=1;

	for (i=0; i<size-1; i++)
		if (a[i]>a[i+1]) {s--; break;}

return s;}
*/


int main()
{
	int c, n, *a, NUM;
//	int  S=1;

//	cout<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;
	a = new int[n];
	for (i=0; i<n; i++)
		cin>>a[i];

/*	do
	{	if(S==0) cout<<"Sorry, the given array is not sorted. Pls ";
		cout<<"Input "<<n<<" integers in ascending order..."<<endl;
		for (i=0; i<n; i++)
			cin>>a[i];
	}while(S==0); */

	sort(a,a+n);
//	cout<<"Input an integer..."<<endl;
		cin>>NUM;

	c=Two_Ptr(a,n,NUM);
//	if(c==0) cout<<endl<<"Sorry, there exists no pair of elements in given array with sum = "<<NUM;
//	else cout<<"(No. of pairs = "<<c<<" )";

	delete[] a;
	return 0;
}


/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format
The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input
5
1
3
4
2
5
5
Sample Output
1 and 4
2 and 3
Explanation
Find any pair of elements in the array which has sum equal to target element and print them.
*/ 