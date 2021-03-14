#include<iostream>
#include<utility>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int R,C;


int Sub_Mat(int A[][3], pii TL, pii BR)
{	
	int i, j, r, c,sum=0;
	r=TL.x;
	c=TL.y;
	i=BR.x;
	j=BR.y;

	cout<<endl<<r<<" "<<c<<" "<<i<<" "<<j<<endl;
	sum+= (A[i][j] + A[r-1][c-1]) - (A[r-1][j] + A[i][c-1]);

	sum+=A[i][j];

	if(r)				//if(r>=1)
		sum-=A[r-1][j];

	if(c)
		sum-=A[i][c-1];

	if(r&&c)
		sum+=A[r-1][c-1];

	return sum;
}


int main()
{
	int Q, M, N;
	pii tl, br;

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

	cout<<endl<<"Your matrix has been inputted."<<endl<<endl;

	//Conversion of Matrix into prefix cumulative sum matrix form
	for(R=0; R<M; R++)
		for(C=1; C<N; C++)
			a[R][C]+=a[R][C-1];

	for(C=0; C<N; C++)
		for(R=1; R<M; R++)
			a[R][C]+=a[R-1][C];

	cout<<endl<<"How many submatrix sum querries would you like to enter?"<<endl;
	cin>>Q;

	for(; Q; Q--)
	{
		cout<<endl<<"Input row no.(subscript index) of top left element of the sub matrix..."<<endl;
		cin>>tl.x;
		cout<<"Input column no.(subscript index) of top left element of the sub matrix..."<<endl;
		cin>>tl.y;
		cout<<"Input row no.(subscript index) of bottom right element of the sub matrix..."<<endl;
		cin>>br.x;
		cout<<"Input column no.(subscript index) of bottom right element of the sub matrix..."<<endl;
		cin>>br.y;
		cout<<"Sum of all elements of the given sub matrix = "<<Sub_Mat(a,tl,br)<<endl;
	}

/*	for(R=0; R<M; R++)
		delete[] a[R];
	delete[] a;*/
	return 0;
}