#include <iostream>
using namespace std;

int main()
{
    int i,T,a,b,sum;

    cin>>T;
    for(i=0; i<T; i++)
    {
        sum = 0;

        cin>>a>>b;

        if (a%2==0)
            a = a+1;

        while (a<=b)
        {
            sum = sum + a;
            a = a+2;
        }
        cout<<"Case " <<i+1 <<": " <<sum <<endl;
    }

    return 0;
}
