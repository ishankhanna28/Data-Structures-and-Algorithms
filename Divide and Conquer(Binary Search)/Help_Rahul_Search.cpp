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