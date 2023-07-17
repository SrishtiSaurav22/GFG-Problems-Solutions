#include<bits/stdc++.h>

using namespace std;

int makeProductOne(int arr[], int N)
    {
        int i, num, p=1, cnt=0, flag0=0, numZero=0;

        for(i=0;i<N;i++)
        {
            if(arr[i]==1)
            {
                p=p*1;
            }

            else if(arr[i]==-1)
            {
                p=p*-1;
            }

            else if(arr[i]!=0)
            {
                num=arr[i];

                if(num<0)
                {
                    cnt=cnt+(num*-1)-1;
                    p=p*-1;
                }

                else if (num>0)
                {
                    cnt=cnt+num-1;
                    p=p*1;
                }

            }

            else
            {
                ++numZero;
            }
        }

        if(numZero)
        {
            cnt+=numZero;
            if(p==-1) p=1;
        }


        else
        {
            if(p==-1) cnt+=2;
        }

        return cnt;
    }

int main()
{
    int arr[]={-2,4,0};
    int N=3;

    cout<<"Minimum number of steps required to make the product of the array equal to one: "<<makeProductOne(arr,N)<<endl;

    cout<<endl;
    return 0;
}
