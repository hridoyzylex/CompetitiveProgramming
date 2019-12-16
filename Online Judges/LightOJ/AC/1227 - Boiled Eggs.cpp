#include <iostream>
using namespace std;

int main()
{
    int i,j,n,P,Q,T;
    int totalGM, noOfEggs, weight;
    cin>>T;
    for(i=0; i<T; i++)
    {
        totalGM = 0;
        noOfEggs = 0;

        cin>>n>>P>>Q;
        for(j=0; j<n; j++)
        {
            cin>>weight;
            if( (noOfEggs+1 <= P) && ((totalGM+weight) <= Q) )
            {
                totalGM = totalGM + weight;
                noOfEggs++;
            }
            //else
                //break;
        }
        cout<<"Case " <<i+1 <<": " <<noOfEggs <<endl;
    }

    return 0;
}
