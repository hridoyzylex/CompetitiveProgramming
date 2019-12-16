#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("H.txt", "r", stdin);
    int i,j,N, num, counter, treatGiven;
    cin>>N;
    for(i=0; N!=0; i++)
    {
        counter=0;
        treatGiven=0;

        for(j=0; j<N; j++)
        {
            cin>>num;
            if(num==0)
                treatGiven++;
            else
                counter++;
        }
        cout<<"Case " <<i+1 <<": " <<counter-treatGiven <<endl;

        cin>>N;
    }

    return 0;
}
