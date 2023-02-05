#include<bits/stdc++.h>

using namespace std;

int binarySearchRecursive(int arr[], int l, int h, int k)
{
    if(l>=h)
        return -1;

    int mid=(l+h)/2;

    if(k==arr[mid])
        return mid;

    if(k<arr[mid])
        return binarySearchRecursive(arr,l,mid,k);

    if(k>arr[mid])
        return binarySearchRecursive(arr,mid+1,h,k);

    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    int k=3;

    cout<<"Position of "<<k<<" is: "<<binarySearchRecursive(arr,0,n,k);

    cout<<endl;
    return 0;
}
