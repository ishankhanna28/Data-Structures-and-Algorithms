#include <iostream>
#include<vector>
using namespace std;
    
int main() 
{
    vector<int> v;
    v.reserve(4);
    int n, num;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>num;
        cout<<endl<<"Size = "<<v.size()<<endl;	 
	    cout<<"Capacity = "<<v.capacity()<<endl;
        v.push_back(num);
    }

    cout<<endl<<"Size = "<<v.size()<<endl;	 
	cout<<"Capacity = "<<v.capacity()<<endl;

    cout<<endl;
    for(int x:v)
        cout<<x<<" ";
    
    cout<<endl;
    return 0;
}


/*
Input
5
10 20 30 40 50
*/


/*
Output

Size = 0
Capacity = 4

Size = 1
Capacity = 4

Size = 2
Capacity = 4

Size = 3
Capacity = 4

Size = 4
Capacity = 4

Size = 5
Capacity = 8

10 20 30 40 50
*/