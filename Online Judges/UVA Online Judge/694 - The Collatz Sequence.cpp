#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    freopen("Input.txt", "r", stdin);
    long long i,A,L,n,cycle,a;

    cin>>A>>L;
    for(i=0; A!=-1&&L!=-1; i++)
    {
        a = A;
        cycle = 1;
        while (A>1)
        {
            if ( A%2==1 )
                A=3*A+1;
            else
                A = A/2;

            if(A>L)
                break;

            cycle++;
        }
        cout<<"Case " <<i+1 <<": A = " <<a <<", limit = " <<L <<", number of terms = " <<cycle <<endl;
        cin>>A>>L;
    }
    return 0;
}

