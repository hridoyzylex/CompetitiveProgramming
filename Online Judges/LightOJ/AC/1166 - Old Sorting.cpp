#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int i,j,k,l,n,T,counter, temp;
    int a[105];

    cin>>T;
    for(i=0; i<T; i++)
    {
        counter = 0;
        cin>>n;
        for(j=1; j<=n; j++)
            cin>>a[j];

        for(j=1; j<=n; j++)
        {
            if(a[j]!=j)
            {
                for(k=j+1; k<=n; k++)
                {
                    if(a[k] == j)
                    {
                        temp = a[j];
                        a[j] = a[k];
                        a[k] = temp;
                        counter++;
                    }
                }
            }
        }
        cout<<"Case " <<i+1 <<": " <<counter <<endl;
    }
    return 0;
}
