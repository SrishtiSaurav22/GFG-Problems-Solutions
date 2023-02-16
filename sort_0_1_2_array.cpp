#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int> vec)
{
    vector<int>::iterator itr;

    for(itr=vec.begin();itr!=vec.end();itr++)
        cout<<*itr<<"\t";
}

// this function takes O(3n)
vector<int> sort012(vector<int> vec)
{
    int i,n0=0,n1=0,n2=0;

    vector<int>::iterator itr;

    // counting the frequency of the three numbers
    for(itr=vec.begin();itr!=vec.end();itr++)
    {
        if(*itr==0)
            ++n0;

        if(*itr==1)
            ++n1;

        if(*itr==2)
            ++n2;
    }

    // clear all vector elements making its size zero
    vec.clear();

    // replacing the elements of the vector with those in the right order
    for(i=0;i<n0;i++)
        vec.push_back(0);

    for(i=0;i<n1;i++)
        vec.push_back(1);

    for(i=0;i<n2;i++)
        vec.push_back(2);

    return vec;
}

int main()
{
    vector<int> vec;

    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);

    cout<<"Vector before sorting:"<<endl;
    printVector(vec);

    vec=sort012(vec);
    cout<<endl;

    cout<<"Vector after sorting:"<<endl;
    printVector(vec);

    cout<<endl;
    return 0;
}
