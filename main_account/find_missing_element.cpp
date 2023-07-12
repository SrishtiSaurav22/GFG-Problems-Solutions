#include<bits/stdc++.h>

using namespace std;

int findMissingElement(vector<int> vec, int n)
{
    int expectedSum=(n*(n+1))/2;
    int sum=0;

    vector<int>::iterator itr;

    for(itr=vec.begin();itr!=vec.end();itr++)
        sum=sum+*itr;

    return expectedSum-sum;
}

int main()
{
    vector<int> vec;

    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(10);
    vec.push_back(5);

    cout<<"Missing element: "<<findMissingElement(vec,10)<<endl;

    cout<<endl;
    return 0;
}
