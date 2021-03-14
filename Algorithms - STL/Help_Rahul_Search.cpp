#include<iostream>
#include<algorithm>
using namespace std;

int main()
{							  //0 1 2 3 4
	int i, N, *a, min=0, num; //4 5 1 2 3
							  //1 2 3 4 5
	int index, temp;
	cin>>N;
	a = new int[N];

	for(i=0; i<N; i++)
	{
		cin>>a[i];

		if(a[i]<a[min])
			min=i;
	}

	temp=a[N-1];
	rotate(a, a+min, a+N);
	cin>>num;	

	if(binary_search(a,a+N,num))
	{
		index = ( lower_bound(a,a+N,num) - a);

		if(a[index]>temp)
			index -= (min+1);

		else 
			index += min;

		cout<<index;
	}

	else
		cout<<-1;

	delete[] a;
	return 0;
}

/*
Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array. Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

Hint - Think Binary Search!



Input Format
The first line contains N - the size of the array. the next N lines contain the numbers of the array.The next line contains the item to be searched.

Constraints
Output Format
Output the index of number in the array to be searched. Output -1 if the number is not found.

Sample Input
5
4
5
1
2
3
2
Sample Output
3
Explanation
The given rotated array is [4, 5, 1, 2, 3]. The element to be searched is 2 whose index is 3.
*/