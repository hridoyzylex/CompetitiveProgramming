#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("L.txt", "r", stdin);

    int i, j, T, P, L, totalAte;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>P>>L;
        totalAte = P-L;

        cout<<"Case " <<i+1 <<":";

        for(j=1; j<=totalAte; j++)
        {
            if(totalAte%j==0)
                cout<<" " <<j;
        }
        cout<<endl;
    }
    return 0;
}
