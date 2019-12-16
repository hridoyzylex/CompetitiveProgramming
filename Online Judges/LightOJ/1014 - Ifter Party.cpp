#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int i,j,N,L,P,Q, pAte;

    cin>>N;
    for(i=0; i<N; i++)
    {
        cin>>P>>L;
        Q = L + 1;
        pAte = P-L;

        cout<<"Case " <<i+1 <<":" ;

        if(Q>pAte)
            cout<<" impossible" <<endl;

        else
        {
            for(j=Q; j<pAte/2; j++)
            {
                if(pAte%j==0)
                    cout<<" " <<j ;
            }

            if(pAte%2==0)
                cout<<" " <<pAte/2;

                cout<<" " <<pAte ;

            cout<<endl;
        }
    }

    return 0;
}
