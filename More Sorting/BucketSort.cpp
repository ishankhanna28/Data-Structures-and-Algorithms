//WAP to rank(sort) Students by their marks.
#include <iostream>
#include <string>
#include <vector>
#include <climits> //for INT_MIN
using namespace std;


class Student
{
    public:
	string name;
	int mks;
};


void BucketSort(Student s[], int n, int max)
{
	const int K2 = max+1;
	vector<Student> v[K2];

	for(int i=0; i<n; i++)
		v[s[i].mks].push_back(s[i]);

	for(int i=max, j=0; i>=0; i--)
		for(auto x:v[i])
			s[j++]=x;
}



int main()
{
	int N, Max=INT_MIN;
	cin>>N;
	const int K1=N;
	Student S[K1];

	for(int i=0; i<N; i++)
	{
		cin>>S[i].mks>>S[i].name;
		Max= max(Max, S[i].mks);
	}

	BucketSort(S, N, Max);

	for(int i=0; i<N; i++)
		cout<<S[i].name<<" "<<S[i].mks<<endl;

	return 0;
}

