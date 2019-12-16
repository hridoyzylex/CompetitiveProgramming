#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int i,n,flag;
    int arr[3005];
    int dif[3005];

    while(cin>>n)
    {
        flag = 1;

        for(i=0; i<n; i++)
            cin>>arr[i];

        for(i=0; i<n-1; i++)
        {
            dif[i] = fabs(arr[i+1] - arr[i]);
        }

        sort(dif, dif+n-1);

        for(i=0; i<n-1; i++)
        {
            if(dif[i] != i+1)
            {
                flag=0;
                break;
            }
        }

        if(flag)
            cout<<"Jolly" <<endl;
        else
            cout<<"Not jolly" <<endl;
    }
    return 0;
}
