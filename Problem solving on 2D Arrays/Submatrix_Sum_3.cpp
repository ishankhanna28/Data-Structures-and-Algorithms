#include<iostream>
using namespace std;
int R,C;

int Sub_Mat(int A[][3], int m, int n)
{
	int sum=0;

//Sum+= A[i][j]*No. of submatrices in which A[i][j] appears for all matrix elements.
	for(R=0; R<m; R++)
		for(C=0; C<n; C++)
			sum+= A[R][C]*(R+1)*(C+1)*(m-R)*(n-C);

	return sum;
}


int main()
{
	int M, N;
	cout<<"How many rows do you want in the matrix?"<<endl;
	cin>>M;
	cout<<"How many columns do you want in the matrix?"<<endl;
	cin>>N;
	cout<<endl<<"Input matrix elements...";

/*	int **b = new int*[M];
	for(R=0; R<M; R++)
		b[M]=new int[N];*/
	int b[3][3];

	for(R=0; R<M; R++)
	{
		cout<<endl<<R+1<<"th Row: Input "<<N<<" integers..."<<endl;
		for(C=0; C<N; C++)
			cin>>b[R][C];
	}

	cout<<endl<<endl<<"Total sum of the sum of all submatrices of the given matrix = "<<Sub_Mat(b,M,N);

/*	for(R=0; R<M; R++)
		delete[] b[R];
	delete[] b;*/
	return 0;
}