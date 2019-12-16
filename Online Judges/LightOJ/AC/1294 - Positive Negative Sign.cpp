#include <iostream>
using namespace std;

int main()
{
    long long i,T,n,m;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n>>m;
        cout<<"Case " <<i+1 <<": " <<(n*m)/2 <<endl;
    }

    return 0;
}
