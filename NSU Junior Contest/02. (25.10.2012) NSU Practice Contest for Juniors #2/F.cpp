#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("F.txt", "r", stdin);
    int i, T,L,W,H;

    cin>>T;
    for (i=0; i<T; i++)
    {
        cin>>L>>W>>H;

        if ((L<=20)&&(W<=20)&&(H<=20))
            cout<<"Case " <<i+1 <<": good" <<endl;
        else
            cout<<"Case " <<i+1 <<": bad" <<endl;
    }
    return 0;
}
