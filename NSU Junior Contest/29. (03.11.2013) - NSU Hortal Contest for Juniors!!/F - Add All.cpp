#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("F.txt", "r", stdin);
    long long i,cost, sum, N;
    long long a[5005];

    cin>>N;
    while(N!=0)
    {
        sum = 0;
        cost = 0;
        for(i=0; i<N; i++)
        {
            cin>>a[i];
        }

        sort(a, a+N);

        if(N==2)
            cout<<a[0]+a[1] <<endl;
        else
        {
            sum = a[0] + a[1];
            cost  = sum;

            for(i=2; i<N; i++)
            {
                sum = sum + a[i];
                cost = cost + sum;
            }
            cout<<cost <<endl;
        }

        cin>>N;
    }
    return 0;
}
