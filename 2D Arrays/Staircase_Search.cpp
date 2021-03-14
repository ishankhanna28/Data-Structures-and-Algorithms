#include<iostream>
#include <algorithm>
using namespace std;
int R, C;

int Staircase_Search(int **A, int M, int N, int num)
{
	int f=0;
	R=0; 
	C=N-1;

	while(R<M && C<N && !f)
	{
		if(A[R][C]>num) 
			C--;

		else if(A[R][C]<num)
			R++;

		else 
			f++;
	}

return f;
}


int Check_Sort(int **A, int M, int N)
{
	int s=1;

	for(R=0; R<M; R++)
		for(C=0; C<N-1; C++)
			if(A[R][C]>A[R][C+1])
				s--;

	for(C=0; C<N; C++)
		for(R=0; R<M-1; R++)
			if(A[R][C]>A[R+1][C])
				s--;

return s;
}



int main()
{
	int m, n, S=1, F, NUM;
	cout<<"How many rows do you want in the matrix?"<<endl;
	cin>>m;
	cout<<"How many columns do you want in the matrix?"<<endl;
	cin>>n;

	int **A = new int*[m];
	for(R=0; R<m; R++)
		A[R] = new int[n];

	do
	{
		if(S==0)
			cout<<endl<<"Sorry, the given array is not row-wise AND column-wise sorted in ascending order!"<<endl;

		cout<<endl<<"Input matrix elements.Ensure that matrix is row-wise and column-wise sorted in ascending order..."<<endl;
		for(R=0; R<m; R++)
		{
			cout<<endl<<R+1<<"th ROW. Input "<<n<<" integers..."<<endl;
			for(C=0; C<n; C++)
				cin>>A[R][C];
		}

		S=Check_Sort(A,m,n);
	}while(!S);

	cout<<endl<<"Which integer do you want to search in the matrix?"<<endl;
	cin>>NUM;

	F=Staircase_Search(A,m,n,NUM);

	if(!F)
		cout<<endl<<"Sorry, "<<NUM<<" was not found in the given matrix.";
	else
		cout<<endl<<NUM<<" was found at row index = "<<R<<" and column index = "<<C<<" of the given matrix.";
		cout<<endl<<"i.e. found at index = ("<<R<<","<<C<<")";
	
	for(R=0; R<m; R++)
		delete[] A[R];
	delete[] A;
	return 0;
}