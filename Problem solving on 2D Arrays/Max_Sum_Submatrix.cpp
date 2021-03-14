#include<iostream>
#include<utility>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int R,C;


int Sub_Mat(int A[][3], int m, int n)
{	
	pii tl;
	int B[3][3];
	for(R=0; R<m; R++)
		for(C=0; C<n; C++)
			B[R][C]=A[R][C];

	int max=A[0][0];
	//Convert initial matrix(IM) into suffix cumulative sum matrix(SCSM)
	for(R=m-1; R>=0; R--)
		for(C=n-2; C>=0; C--)
			A[R][C]+=A[R][C+1];

	for(C=n-1; C>=0; C--)
		for(R=m-2; R>=0; R--)
			A[R][C]+=A[R+1][C];

	//Largest element of SCSM will be max.sum sub_mat of IM(MSSB). BR of IM is always BR of MSSB. Pos. correspond to TL.
	for(R=0; R<m; R++)
	{
		for(C=0; C<n; C++)
		{
			if(A[R][C]>max)
			{
				max=A[R][C];
				tl.x=R;
				tl.y=C;
			}
		}
	}

	cout<<endl<<"The Max. Sum submatrix of given matrix is..."<<endl;
	for(R=tl.x; R<m; R++)
	{
		for(C=tl.y; C<n; C++)
		{
			cout<<B[R][C]<<" ";
		}

		cout<<endl;
	}

	return max;	
}


int main()
{
	int Q, M, N, sum;
	pii tl, br;

	cout<<"How many rows do you want in the matrix?"<<endl;
	cin>>M;
	cout<<"How many columns do you want in the matrix?"<<endl;
	cin>>N;
	cout<<endl<<"Input elements of a ROW-WISE AND COLUMN-WISE sorted matrix...";

/*	int **a = new int*[M];
	for(R=0; R<M; R++)
		a[M]=new int[N];*/
	int a[3][3];
	
	for(R=0; R<M; R++)
	{
		cout<<endl<<R+1<<"th Row: Input "<<N<<" integers..."<<endl;
		for(C=0; C<N; C++)
			cin>>a[R][C];
	}

	cout<<endl<<"The input matrix is..."<<endl;
	for(R=0; R<M; R++)
	{
		for(C=0; C<N; C++)
		{
			cout<<a[R][C]<<" ";
		}

		cout<<endl;
	}
	cout<<endl<<"Your matrix has been inputted."<<endl<<endl;

	sum=Sub_Mat(a,M,N);
	cout<<"The maximum sum = "<<sum;

/*	for(R=0; R<M; R++)
		delete[] a[R];
	delete[] a;*/
	return 0;
}
