#include<iostream>
using namespace std;

int arrcount[1001];

int main()
{
    int i,n,a,index;
    int max = 0;

    cin>>n;
    int arr[n];

    for(i=0; i<n; i++)
    {
        cin>>a;
        arr[i] = a;
    }


    for(i=0; i<n; i++)
    {
        arrcount[arr[i]]++;
    }

    max = arrcount[0];

    for(i=1; i<=1000; i++)
    {
        if(arrcount[i] > max)
        {
            max = arrcount[i];
        }
    }

    if ((n-max)>=max-1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
