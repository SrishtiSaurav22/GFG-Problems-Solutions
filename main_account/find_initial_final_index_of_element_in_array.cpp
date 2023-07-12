/*
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

EXAMPLE 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output: 2 5
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5.

EXAMPLE 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output: 6 6

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.
Note: If the number x is not found in the array just return both index as -1.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 107
*/

#include<bits/stdc++.h>

using namespace std;

// RECURSIVE APPROACH

int findInitial(int arr[], int n, int x, int i)
{
    if(i==n)
        return -1;

    if(arr[i]==x)
        return i;

    else
        return findInitial(arr,n,x,i+1);
}

int findFinal(int arr[], int n, int x, int i)
{
    if(i==-1)
        return -1;

    if(arr[i]==x)
        return i;

    else
        return findFinal(arr,n,x,i-1);
}

vector<int> findRecursive(int arr[], int n , int x)
{
    int ini=findInitial(arr,n,x,0);
    int fin=findFinal(arr,n,x,n-1);

    vector<int> v;

    // this is the order as elements are inserted at the back of the vector
    v.push_back(ini);
    v.push_back(fin);

    return v;
}

int findInitial(int arr[], int n, int x)
{
    int i;

    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
            return i;
    }

    return -1;
}

// ITERATIVE APPROACH

int findFinal(int arr[], int n, int x)
{
    int i;

    for(i=n-1;i>=0;i--)
    {
        if(arr[i]==x)
            return i;
    }

    return -1;
}


vector<int> findIterative(int arr[], int n, int x)
{
    int i,j;

    int ini=findInitial(arr,n,x);
    int fin=findFinal(arr,n,x);

    vector<int> v;

    // this is the order as elements are inserted at the back of the vector
    v.push_back(ini);
    v.push_back(fin);

    return v;
}

// Both the solutions passed all test cases? Should they (since the time complexity should be O(logN)? Which approach satisfies that?

int main()
{
    int arr[]={1,2,5,5,5,5,7,8};

    cout<<"Using recursive method:\n";
    cout<<findRecursive(arr,8,5)[0]<<"\t"<<findRecursive(arr,8,5)[1]<<endl;

    cout<<"Using iterative method:\n";
    cout<<findIterative(arr,8,5)[0]<<"\t"<<findIterative(arr,8,5)[1]<<endl;

    cout<<endl;
    return 0;
}


