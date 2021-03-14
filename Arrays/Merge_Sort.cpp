#include<iostream>
using namespace std;
int i, j, k;

void Merge_Sort(int*C, int A[], int M, int B[], int N)
{
	i=0, j=0, k=0;

	while(i<M && j<N)
	{
		if(A[i]<B[j]) 
			C[k++]=A[i++];

		else if(B[j]<A[i]) 
			C[k++]=B[j++];
	
		else
		{
			C[k++]=A[i++];
			C[k++]=B[j++];
		}
	}

	while(i<M) 
		C[k++]=A[i++];

	while(j<N) 
		C[k++]=B[j++];

	cout<<endl<<"The 2 given arrays have been merged"<<endl;
}


int Check_Sort(int Ar[], int x)
{int s=1;
	for(i=0; i<x-1; i++)
		if(Ar[i]>Ar[i+1]) {s--; break;}
return s;}


int main()
{int m, n, *a, *b, *C, S1=1, S2=1;

cout<<"How many integers do you want to input in the FIRST ARRAY?"<<endl;
cin>>m;
a=new int[m];
do{
	if(S1==0) cout<<endl<<"Sorry, the given array is not sorted. Pls input "<<m<<" integers again in ascending order."<<endl;
	else cout<<"Input "<<m<<" integers in ascending order..."<<endl;

	for(i=0; i<m; i++)
		cin>>a[i];

	S1=Check_Sort(a, m);
}while(S1==0);

cout<<"How many integers do you want to input in the SECOND ARRAY?"<<endl;
cin>>n;
b=new int[n];
do{
	if(S2==0) cout<<endl<<"Sorry, the given array is not sorted. Pls input "<<n<<" integers again in ascending order."<<endl;
	else cout<<"Input "<<n<<" integers in ascending order..."<<endl;

	for(i=0; i<n; i++)
		cin>>b[i];

	S2=Check_Sort(b, n);
}while(S2==0);

C = new int[m+n];
Merge_Sort(C, a, m, b, n);
cout<<endl<<"The merged array is..."<<endl;

for(i=0; i<m+n; i++)
		cout<<C[i]<<" ";
cout<<endl;

delete[] a;
delete[] b;
delete[] C;
return 0;
}
