#include <iostream>
using namespace std;

int main()
{
    int i,n,number, Even=0, Odd=0;
    int a[101];

    for(i=0; i<=100; i++)
        a[i] = -1;

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>number;
        a[i] = number;

        if(number%2==0)
            Even++;
        else
            Odd++;
    }

    if(Odd==1)
    {
        for(i=0; i<100; i++)
        {
            if(a[i]%2 != 0)
            {
                cout<<i+1 <<endl;
                break;
            }
        }
    }

    else if(Even==1)
    {
        for(i=0; i<100; i++)
        {
            if(a[i]%2 == 0)
            {
                cout<<i+1 <<endl;
                break;
            }
        }
    }

    return 0;
}
