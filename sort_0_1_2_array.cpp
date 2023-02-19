/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

EXAMPLE 1:

Input:
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated
into ascending order.

EXAMPLE 2:

Input:
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int> vec)
{
    vector<int>::iterator itr;

    for(itr=vec.begin();itr!=vec.end();itr++)
        cout<<*itr<<"\t";
}

// this approach is for arrays
vector<int> sort012_pointers_for_array(vector<int> vec)
{
    int low=0,mid=0,high=vec.size()-1;

    while(mid<high)
    {
        if(vec[mid]==0)
        {
            swap(vec[mid],vec[low]);
            ++mid;
            ++low;
        }

        else if(vec[mid]==1)
        {
            ++mid;
        }

        else if(vec[mid]==2)
        {
            swap(vec[mid],vec[high]);
            --high;
        }
    }

    return vec;
}

vector<int> sort012_pointers_for_vector(vector<int> vec)
{
    int i;

    while(i<vec.size())
    {
        if(vec[i]==0)
        {
            if(i!=0 && vec[i-1]!=0)
            {
                vec.erase(vec.begin()+i);
                vec.insert(vec.begin(),0);
            }
        }

        else if(vec[i]==1)
            ++i;

        else if(vec[i]==2)
        {
            vec.erase(vec.begin()+i);
            vec.push_back(2);
        }
    }

    return vec;
}

// this function takes O(3n)
// find solution that takes O(n) time?
// the two main things are that: array should be sorted in place and that it should be done in O(n) time
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

    vec=sort012_pointers_for_vector(vec);
    cout<<endl;

    cout<<"Vector after sorting:"<<endl;
    printVector(vec);

    cout<<endl;
    return 0;
}
