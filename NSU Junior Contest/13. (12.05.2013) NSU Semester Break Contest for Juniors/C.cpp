#include <iostream>
using namespace std;

int main()
{
    int a,b,m,n,total = 0;

    while(cin>>m>>n)
    {
        if(m>=n)
        {
            a = m;
            b = n;
        }
        else
        {
            a = n;
            b = m;
        }

        if(b>=1)
            total = (b-1) + (a-1)*b;
        else
            total = a-1;

        cout<<total<<endl;
    }

    return 0;
}
