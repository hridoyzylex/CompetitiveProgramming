#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int G,C,N,i,j,k;
    int a[1005];

    cin>>N;
    for(i=0; i<N; i++)
    {
        cin>>G;
        for(j=0; j<G; j++)
        {
            cin>>a[j];
        }

    sort(a, a+G);
    //for(k=0; k<G; k++)
        //cout<<a[k] <<" ";
        //cout<<endl;

    for(k=0; k<G; )
    {
        if(a[k]!= a[k+1])
        {
            cout<<"Case #" <<i+1 <<": " <<a[k] <<endl;
            break;
        }
        else
        {
            k = k+2;
        }
    }


    }

    return 0;
}
