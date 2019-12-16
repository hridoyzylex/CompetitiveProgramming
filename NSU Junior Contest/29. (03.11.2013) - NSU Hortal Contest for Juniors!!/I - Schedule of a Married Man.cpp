#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("I.txt", "r", stdin);
    int i,j,T,h1,h2,m1,m2;
    int startTimeA, endTimeA, startTimeM, endTimeM;

    cin>>T;
    for(i=0; i<T; i++)
    {
        scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
        startTimeA = h1*100+m1;
        endTimeA = h2*100+m2;

        scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
        startTimeM = h1*100+m1;
        endTimeM = h2*100+m2;

        //cout<<startTimeA <<" " <<endTimeA <<endl;
        //cout<<startTimeM <<" " <<endTimeM <<endl;

        if((startTimeM<startTimeA&&endTimeM<startTimeA) || (startTimeM>endTimeA&&endTimeM>endTimeA))
            cout<<"Case " <<i+1 <<": Hits Meeting" <<endl;
        else
            cout<<"Case " <<i+1 <<": Mrs Meeting" <<endl;
    }

    return 0;
}
