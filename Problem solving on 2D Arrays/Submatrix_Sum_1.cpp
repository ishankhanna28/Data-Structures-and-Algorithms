#include<iostream>
using namespace std;
int R,C;


int Sub_Mat(int A[][3], int m, int n)
{	
	int r, c, i, j, sum=0;

	for(r=0; r<m; r++)
	{
		for(c=0; c<n; c++)
		{
			for(i=r; i<m; i++)
			{	
				for(j=c; j<n; j++)
				{
//					sum+= (A[i][j] + A[r-1][c-1]) - (A[r-1][j] + A[i][c-1]);

					sum+=A[i][j];

					if(r)				//if(r>=1)
						sum-=A[r-1][j];

					if(c)
						sum-=A[i][c-1];

					if(r&&c)
						sum+=A[r-1][c-1];
				}
			}
		}

	}

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


	for(R=0; R<M; R++)
		for(C=1; C<N; C++)
			a[R][C]+=a[R][C-1];

	for(C=0; C<N; C++)
		for(R=1; R<M; R++)
			a[R][C]+=a[R-1][C];

/*	cout<<endl<<endl;
	for(R=0; R<M; R++)
		{
			for(C=0; C<N; C++)
			{
				cout<<a[R][C]<<" ";
			}
			
			cout<<endl;
		}
*/

	cout<<endl<<endl<<"Total sum of the sum of all submatrices of the given matrix = "<<Sub_Mat(a,M,N);
/*	for(R=0; R<M; R++)
		delete[] a[R];
	delete[] a;*/
	return 0;
}
