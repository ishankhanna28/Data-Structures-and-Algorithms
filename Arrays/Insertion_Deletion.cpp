#include<iostream>
#include<stdlib.h>
using namespace std;
int i;

void INSERT(int *A, int *N, int pos, int num)
{
	for(i=(*N)-1; i>=pos; i--)
		A[i+1]=A[i];

	A[pos]=num;
	(*N)++;
	cout<<endl<<"Element "<<num<<" has been inserted at "<<pos<<"th subscript value."<<endl;
}

void DELETE(int *A, int *N, int Pos)
{(*N)--;
cout<<endl<<"Element "<<A[Pos]<<" at "<<Pos<<"th subscript value has been deleted."<<endl;
	for(i=Pos; i<(*N); i++)
		A[i]=A[i+1];
}

int Get_Arr(int *A)
{int n;

	cout<<endl<<"How many integers do you want to enter in your array ?"<<endl;
	cin>>n;
	A=(int*)realloc(A, n*sizeof(int));

	cout<<"Input "<<n<<" integers..."<<endl;
	for (i=0; i<n; i++)
		cin>>A[i];
return n;}

void Disp_Arr(int *A, int *N)
{cout<<endl<<"The Array is ..."<<endl;
	for (i=0; i<*N; i++)
		cout<<A[i]<<" ";
cout<<endl;}

int main()
{int s, N, NUM, POS, *A = new int[2];
 char ch;

	do{
		cout<<endl<<endl<<"\t\tARRAY MANIPULATOR"<<endl<<endl;
		cout<<"Pls make your choice..."<<endl;
		cout<<"\t1) Input Array"<<endl;
		cout<<"\t2) Display Array"<<endl;
		cout<<"\t3) Insert element in array"<<endl;
		cout<<"\t4) Delete element from array"<<endl;
		cout<<"\t5) Exit"<<endl;
		cout<<"Make your choice (1/2/3/4/5)..."<<endl;
		cin>>s;

		switch(s)
			{case 1:N=Get_Arr(A); break;
			 case 2:Disp_Arr(A, &N); break;

			 case 3:cout<<endl<<"Which integer do you want to insert in the Array?"<<endl;
			 		cin>>NUM;
			 		cout<<"At which position(subscript value) do you want to insert an element in the Array?"<<endl;
			 		cin>>POS;
			 		INSERT(A,&N,POS,NUM);
			 		break;

			case 4: cout<<endl<<"Enter the subscript index value of element you would like to delete from the array..."<<endl;
					cin>>POS;
					DELETE(A,&N,POS);
					break;

			case 5: cout<<endl<<"Quitting Program..."<<endl;
					exit(0);

			default: cout<<endl<<"ERROR: Invalid Input"<<endl;
			}

		cout<<endl<<"Would you like to continue(Y/N) ?";
		cin>>ch;
	}while(ch=='Y'||ch=='y');

if(ch=='N'||ch=='n') exit(0);
delete[] A;
return 0;
}












