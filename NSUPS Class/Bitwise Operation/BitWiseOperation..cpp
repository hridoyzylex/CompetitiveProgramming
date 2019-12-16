#include <iostream>
using namespace std;

int main()
{

    int i,j, temp;
    int a[4] = {0,0,0,0};

    i=2;

    for(j=0; j<4; j++)
    {
        if( i&(1<<j) )
        {
            a[j] = 1;
        }
    }

    for(i=0; i<2; i++)
    {
        temp = a[i];
        a[i] = a[3-i];
        a[3-i] = temp;
    }

    for(i=0; i<4; i++)
        cout<<a[i];

    return 0;
}
