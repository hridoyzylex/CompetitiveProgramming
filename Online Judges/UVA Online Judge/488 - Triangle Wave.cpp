#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int i,j,k,l,T,a,f;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>a>>f;
        for(j=0; j<f; j++)
        {
            for(k=1; k<=a; k++)
            {
                for(l=0; l<k; l++)
                {
                    cout<<k;
                }
                cout<<endl;
            }
            for(k=a-1; k>0; k--)
            {
                for(l=0; l<k; l++)
                {
                    cout<<k;
                }
                cout<<endl;
            }

            if(j==f-1 && i==T-1) continue;
                cout<<endl;
        }
    }

    return 0;
}
