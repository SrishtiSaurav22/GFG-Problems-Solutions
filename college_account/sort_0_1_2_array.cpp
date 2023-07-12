#include<bits/stdc++.h>

using namespace std;

void sort012(int a[], int n)
{
    int i, j, n0=0, n1=0, n2=0;

    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        ++n0;

        if(a[i]==1)
        ++n1;

        if(a[i]==2)
        ++n2;
    }

    for(i=0;i<n0;i++)
        a[i]=0;

    for(j=i;j<n0+n1;j++)
        a[j]=1;

    for(i=j;i<n0+n1+n2;i++)
        a[i]=2;
}

void printArray(int arr[], int n)
{
    int i;

    for(i=0;i<n;i++)
        cout<<arr[i]<<"\t";
}

int main()
{
    int n=5;
    int arr[]={0,2,1,2,0};

    cout<<"Before sorting:\n";
    printArray(arr,n);
    cout<<endl;

    sort012(arr,n);
    cout<<endl;

    cout<<"After sorting:\n";
    printArray(arr,n);
    cout<<endl;

    cout<<endl;
    return 0;
}

