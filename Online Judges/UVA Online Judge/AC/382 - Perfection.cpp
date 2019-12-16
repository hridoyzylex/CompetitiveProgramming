#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int i,n,sum;

    cout<<"PERFECTION OUTPUT" <<endl;
    while(cin>>n && n!=0)
    {
        sum = 0;
        for(i=1; i<=n/2; i++)
        {
            if(n%i == 0)
                sum = sum + i;
        }

        if(sum==n)
            printf("%5d  PERFECT\n",n);
        else if(sum<n)
            printf("%5d  DEFICIENT\n",n);
        else
            printf("%5d  ABUNDANT\n",n);
    }

    cout<<"END OF OUTPUT" <<endl;
    return 0;
}
