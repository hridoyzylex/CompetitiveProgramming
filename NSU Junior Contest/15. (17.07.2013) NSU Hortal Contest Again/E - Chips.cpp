#include <iostream>
using namespace std;

int main()
{
    int i,m,n;

    cin>>n>>m;
    for(i=1; m>0; i++)
    {
        if(i<=m)
        {
            m = m - i;

            if(i==n)
            i=0;
        }
        else
            break;
    }

    cout<<m <<endl;

    return 0;
}
