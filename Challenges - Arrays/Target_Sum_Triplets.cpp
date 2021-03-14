#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k;

int Triplets(int A[], int N, int num)
{
	int sum=0, count=0;

	for(k=0; k<N-2; k++)
	{
		i=k+1;
		j=N-1;;

		while(i<j)
		{
			sum = A[i] + A[j] + A[k];

			if(sum<num)
				i++;

			else if(sum>num)
				j--;

			else
			{
			//	if(count++==0) cout<<endl<<"The Pairs of elements of given array whoose sum = "<<num<<" are ..."<<endl;
			//	cout<<count<<") ";
				cout<<A[k]<<", "<<A[i]<<" and "<<A[j]<<endl;
				i++;
				j--;
			}	
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

	c=Triplets(a,n,NUM);
//	if(c==0) cout<<endl<<"Sorry, there exists no pair of elements in given array with sum = "<<NUM;
//	else cout<<"(No. of pairs = "<<c<<" )";

	delete[] a;
	return 0;
}


/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.

Input Format
First line contains input N.
Next line contains N space separated integers denoting the elements of the array.
The third line contains a single integer T denoting the target element.

Constraints
Length of Array should be between 1 and 1000.

Output Format
Print all the triplet present in the array in a new line each. The triplets must be printed as A, B and C where A,B and C are the elements of the triplet ( A<=B<=C) and all triplets must be printed in sorted order. Print only unique triplets.

Sample Input
9
5 7 9 1 2 4 6 8 3
10
Sample Output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
Explanation
Array = {5, 7, 9, 1, 2, 4, 6 ,8 ,3}. Target number = 10. Find any three number in the given array which sum to target number.
*/