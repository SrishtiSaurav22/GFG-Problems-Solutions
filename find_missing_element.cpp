#include<bits/stdc++.h>

using namespace std;

int find_missing_element(vector<int>& arr, int n)
{
    int i;

    for(i=1;i<=n;i++)
    {
        if(*find(arr.begin(),arr.end()+1,i)==0)
            return i;
    }

    return 0;
}

int main()
{
    vector<int> vec;

    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(7);

    cout<<"Missing element: "<<find_missing_element(vec,7)<<endl;
    // if result is zero there's no missing element, but that won't be the case

    cout<<*find(vec.begin(),vec.end()+1,5); //return the iterator to that element

    cout<<endl;
    return 0;
}
