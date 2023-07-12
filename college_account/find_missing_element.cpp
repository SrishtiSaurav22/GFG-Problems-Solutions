#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& array, int n)
{
    int i, expectedSum=0, actualSum=0;

    expectedSum=(n*(n+1))/2;

    vector<int>::iterator itr;

    for(itr=array.begin();itr!=array.end();itr++)
    {
        actualSum+=(*itr);
    }

    return expectedSum-actualSum;
}

int main()
{
    vector<int> arr;
    int n=2;

    arr.push_back(1);

    /*
    In case of n=1, you can comment the above line since only the
    missing element is also the only element in the vector, so it's empty.
    */

    vector<int>::iterator itr;

    for(itr=arr.begin();itr!=arr.end();itr++)
        cout<<*itr<<"\t";

    cout<<endl;
    cout<<"Missing number="<<missingNumber(arr,n);

    cout<<endl;
    return 0;
}

